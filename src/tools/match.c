/*
** match.c for tools in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 26 12:09:25 2017 Ronan Boiteau
** Last update Sun Feb 26 12:13:43 2017 Ronan Boiteau
*/

#include <stdbool.h>
#include <stdlib.h>

int	nmatch(char const *str1, char const *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (false);
  else if ((*str1 == '\0') && (*str2 == '\0'))
    return (true);
  else if ((*str1 != '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1) + nmatch(str1 + 1, str2));
  else if ((*str1 == '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1));
  else if ((*str2 != '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2) + nmatch(str1, str2 + 1));
  else if ((*str2 == '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2));
  else if (*str1 == *str2)
    return (nmatch(str1 + 1, str2 + 1));
  else
    return (false);
}

int	match(char const *str1, char const *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (false);
  if (nmatch(str1, str2) > 0)
    return (true);
  return (false);
}
