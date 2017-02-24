/*
** my_char_isprintable.c for tools in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 16:05:57 2017 Ronan Boiteau
** Last update Fri Feb 24 16:07:08 2017 Ronan Boiteau
*/

#include <stdbool.h>

int		my_char_isprintable(char letter)
{
  if (letter >= 32 && letter < 127)
    return (true);
  return (false);
}
