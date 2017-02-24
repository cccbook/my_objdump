/*
** main.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Feb 21 00:32:12 2017 Ronan Boiteau
** Last update Fri Feb 24 16:22:48 2017 Ronan Boiteau
*/

#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include "objdump.h"

static off_t	get_file_size(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

int		main(int argc, char **argv)
{
  void		*data;
  Elf64_Ehdr	*elf;
  int		fd;

  /* while (argc) */
  (void)argc;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (1);
  data = mmap(NULL, get_file_size(fd), PROT_READ, MAP_SHARED, fd, 0);
  elf = (Elf64_Ehdr *)data;
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    return (objdump32(argv[1], data));
  else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    return (objdump64(argv[1], data));
  else
    return (1);
}
