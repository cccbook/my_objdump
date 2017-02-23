/*
** main.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Feb 21 00:32:12 2017 Ronan Boiteau
** Last update Thu Feb 23 21:51:15 2017 Ronan Boiteau
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
  if (letter >= 32 && letter < 127)
    return (true);
  return (false);
}

void		print_content_hex(char *offset,
				  unsigned int idx,
				  unsigned int size)
{
  unsigned int	idx_hex;

  idx_hex = 0;
  while (idx_hex < 16)
    {
      if (idx + idx_hex < size)
	printf("%02x", *(unsigned char *)(offset + idx + idx_hex));
      else
	printf("  ");
      ++idx_hex;
      if (idx_hex % 4 == 0)
	printf(" ");
    }
  if (idx_hex % 4 != 0)
    printf(" ");
}

void		print_section_content(void *data, Elf64_Shdr *shdr)
{
  unsigned int	idx;
  unsigned int	addr;

  addr = shdr->sh_addr;
  idx = 0;
  while (idx < shdr->sh_size)
    {
      if (idx % 16 == 0)
	{
	  printf(" %04x ", addr);
	  addr += 16;
	  print_content_hex(data + shdr->sh_offset, idx, shdr->sh_size);
	}
      if (my_char_isprintable(*(char *)(data + shdr->sh_offset + idx)) == true)
	printf("%c", *(char *)(data + shdr->sh_offset + idx));
      else
	printf(".");
      ++idx;
      if (idx % 16 == 0)
	printf("\n");
    }
  if (idx % 16 != 0)
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
	  print_section_content(data, shdr + idx);
	}
      ++idx;
    }
}

unsigned int	get_text_address(Elf64_Ehdr const *elf,
				 Elf64_Shdr const *shdr,
				 char const *str_tab)
{
  unsigned int	idx;

  idx = 0;
  while (idx < elf->e_shnum)
    {
      if (my_strcmp(".text", &str_tab[shdr[idx].sh_name]) == 0)
	return (shdr[idx].sh_addr);
      ++idx;
    }
  return (0);
}

int		print_file_headers(char const *prog_name,
				   void const *data,
				   Elf64_Ehdr const *elf,
				   Elf64_Shdr const *shdr)
{
  char		*str_tab;
  unsigned int	text_addr;

  str_tab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:     file format elf64-x86-64", prog_name);
  printf("elf64-x86-64\n");
  printf("architecture: i386:x86-64, flags 0x00000112:\n");
  printf("EXEC_P, HAS_SYMS, D_PAGED\n");
  if ((text_addr = get_text_address(elf, shdr, str_tab)) == 0)
    return (-1);
  printf("start address 0x%016x\n", text_addr);
}

int		main(int argc, char **argv)
{
  void		*data;
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  int		fd;
  char		*str_tab;

  (void)argc;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (1);
  data = mmap(NULL, get_file_size(fd), PROT_READ, MAP_SHARED, fd, 0);
  elf = (Elf64_Ehdr *)data;
  shdr = (Elf64_Shdr *)(data + elf->e_shoff);
  str_tab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
  if (print_file_headers(argv[1], data, elf, shdr) == -1)
    return (1);
  print_sections(data, elf, shdr, str_tab);
  return (0);
}
