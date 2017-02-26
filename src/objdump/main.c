/*
** main.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Feb 21 00:32:12 2017 Ronan Boiteau
** Last update Sun Feb 26 13:45:41 2017 Ronan Boiteau
*/

#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include "objdump.h"
#include "tools.h"

static off_t	get_file_size(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

static void	objdump(char *progname, char *filepath, t_uchar *ret)
{
  int		fd;
  void		*data;
  Elf64_Ehdr	*elf;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    {
      dprintf(2, "%s: '%s': No such file\n", progname, filepath);
      *ret = 1;
    }
  else
    {
      data = mmap(NULL, get_file_size(fd), PROT_READ, MAP_SHARED, fd, 0);
      elf = (Elf64_Ehdr *)data;
      if (elf->e_ident[EI_CLASS] == ELFCLASS32)
	objdump32(filepath, data, ret);
      else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
	objdump64(filepath, data, ret);
      else
	*ret = 1;
      close(fd);
    }
}

int		main(int argc, char **argv)
{
  int		idx;
  t_uchar	ret;
  char		*filepath;

  ret = 0;
  if (argc < 2)
    {
      if ((filepath = my_strdup("a.out")) == NULL)
	exit(1);
      objdump(argv[0], filepath, &ret);
    }
  else
    {
      idx = 1;
      while (idx < argc)
	{
	  objdump(argv[0], argv[idx], &ret);
	  ++idx;
	}
    }
  return (ret);
}
