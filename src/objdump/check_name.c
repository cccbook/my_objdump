/*
** check_name.c for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 16:09:30 2017 Ronan Boiteau
** Last update Sun Feb 26 12:15:38 2017 Ronan Boiteau
*/

#include <stdbool.h>
#include "tools.h"

bool		check_name(char const *name, bool is_exec)
{
  if (is_exec == true)
    {
      if (my_strcmp(name, "") != 0 &&
	  my_strcmp(name, ".bss") != 0 &&
	  my_strcmp(name, ".shstrtab") != 0 &&
	  my_strcmp(name, ".strtab") != 0 &&
	  my_strcmp(name, ".symtab") != 0)
	return (true);
      return (false);
    }
  else
    {
      if (match(name, ".rela.*") != true &&
	  my_strcmp(name, ".data") != 0)
	return (true);
      return (false);
    }
}
