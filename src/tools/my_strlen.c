/*
** my_strlen.c for tools in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 26 13:26:11 2017 Ronan Boiteau
** Last update Sun Feb 26 13:26:15 2017 Ronan Boiteau
*/

#include <stdlib.h>

int		my_strlen(const char *str)
{
  int		idx;

  idx = 0;
  while (str != NULL && str[idx])
    idx += 1;
  return (idx);
}
