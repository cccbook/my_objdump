/*
** main.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Feb 21 00:32:12 2017 Ronan Boiteau
** Last update Thu Feb 23 17:37:51 2017 Ronan Boiteau
*/

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

off_t		get_file_size(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

void		print_file_headers(char const *prog_name)
{
  printf("\n%s:\t\n\n", prog_name);
}

int		my_strcmp(char const *str1, char const *str2)
{
  unsigned int	idx;

  if (str1 == NULL || str2 == NULL)
    return (-1);
  idx = 0;
  while (str1[idx] != '\0' && str2[idx] != '\0')
    {
      if (str1[idx] != str2[idx])
	return (str1[idx] - str2[idx]);
      idx += 1;
    }
  if (str1[idx] == '\0' && str2[idx] == '\0')
    return (0);
  return (-1);
}

bool		check_name(char const *name)
{
  if (my_strcmp(name, "") != 0 &&
      my_strcmp(name, ".bss") != 0 &&
      my_strcmp(name, ".shstrtab") != 0 &&
      my_strcmp(name, ".strtab") != 0 &&
      my_strcmp(name, ".symtab") != 0)
    return (true);
  return (false);
}

int		my_char_isprintable(char letter)
{
  if (!((letter >= 32 && letter <= 126) || letter == '\0'
	|| (letter >= 7 && letter <= 13)))
    return (false);
  return (true);
}

void		print_section_content(void *data, Elf64_Shdr shdr)
{
  unsigned int	idx;

  printf("%x\n", (unsigned int)shdr.sh_addr);
  /* printf("%s\n", data + shdr.sh_offset); */
  idx = 0;
  while (idx < shdr.sh_size)
    {
      if (my_char_isprintable(*(char *)(data + shdr.sh_offset + idx)) == true)
	printf("%c", *(char *)(data + shdr.sh_offset + idx));
      else
	printf(".");
      ++idx;
    }
  printf("\n");
}

void		print_sections(void *data,
			       Elf64_Ehdr *elf,
			       Elf64_Shdr *shdr,
			       char *str_tab)
{
  unsigned int	idx;

  idx = 0;
  while (idx < elf->e_shnum)
    {
      if (check_name(&str_tab[shdr[idx].sh_name]) == true)
	{
	  printf("Contents of section: %s:\n", &str_tab[shdr[idx].sh_name]);
	  print_section_content(data, shdr[idx]);
	}
      ++idx;
    }
}

int		main(int argc, char **argv)
{
  void		*data;
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  int		fd;
  char		*str_tab;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (1);
  data = mmap(NULL, get_file_size(fd), PROT_READ, MAP_SHARED, fd, 0);
  elf = (Elf64_Ehdr *)data;
  shdr = (Elf64_Shdr *)(data + elf->e_shoff);
  str_tab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
  print_file_headers(argv[1]);
  print_sections(data, elf, shdr, str_tab);
  return (0);
}
