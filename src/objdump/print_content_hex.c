/*
** print_content_hex.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 16:11:26 2017 Ronan Boiteau
** Last update Fri Feb 24 16:17:57 2017 Ronan Boiteau
*/

#include <stdio.h>
#include "my_typedef.h"

void		print_content_hex(char *offset, t_uint idx, t_uint size)
{
  t_uint	idx_hex;

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
  printf(" ");
}
