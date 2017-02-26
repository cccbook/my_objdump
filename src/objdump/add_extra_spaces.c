/*
** add_extra_spaces.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 26 14:03:09 2017 Ronan Boiteau
** Last update Sun Feb 26 14:05:42 2017 Ronan Boiteau
*/

#include <stdio.h>
#include "tools.h"
#include "my_typedef.h"

void		add_extra_spaces(t_uint *idx)
{
  if (*idx % 16 != 0)
    {
      while (*idx % 16 != 0)
	{
	  printf(" ");
	  *idx += 1;
	}
      printf("\n");
    }
}
