/*
** objdump.h for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 15:13:23 2017 Ronan Boiteau
** Last update Fri Feb 24 16:24:08 2017 Ronan Boiteau
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <stdbool.h>
# include "my_typedef.h"

bool				check_name(char const *name);
t_uchar				objdump32(char *filepath, void *data);
t_uchar				objdump64(char *filepath, void *data);
void				print_content_hex(char *offset,
						  t_uint idx,
						  t_uint size);

#endif /* !OBJDUMP_H_ */
