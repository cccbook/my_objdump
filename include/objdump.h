/*
** objdump.h for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 15:13:23 2017 Ronan Boiteau
** Last update Sun Feb 26 14:05:53 2017 Ronan Boiteau
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <stdbool.h>
# include "my_typedef.h"

void				add_extra_spaces(t_uint *idx);
bool				check_name(char const *name, bool is_exec);
void				objdump32(char *filepath,
					  void *data,
					  t_uchar *ret);
void				objdump64(char *filepath,
					  void *data,
					  t_uchar *ret);
void				print_content_hex(char *offset,
						  t_uint idx,
						  t_uint size);

#endif /* !OBJDUMP_H_ */
