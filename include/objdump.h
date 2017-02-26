/*
** objdump.h for objdump in /home/ronan/Documents/PSU_2016_nmobjdump
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Fri Feb 24 15:13:23 2017 Ronan Boiteau
** Last update Sun Feb 26 14:55:46 2017 Ronan Boiteau
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <stdbool.h>
# include "my_typedef.h"

off_t		get_file_size(int fd);
void		add_extra_spaces(t_uint *idx);
bool		check_name(char const *name, bool is_exec);
void		objdump32(char *filepath, void *data, t_uchar *ret);
void		objdump64(char *filepath, void *data, t_uchar *ret);
void		print_content_hex(char *offset, t_uint idx, t_uint size);
bool		check_file(char *progname, char *filepath, int fd, void *data);

#endif /* !OBJDUMP_H_ */
