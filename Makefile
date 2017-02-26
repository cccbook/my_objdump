##
## Makefile for nm/objdump in /home/ronan/Documents/PSU_2016_nmobjdump
## 
## Made by Ronan Boiteau
## Login   <ronan.boiteau@epitech.net>
## 
## Started on  Tue Feb 21 00:29:21 2017 Ronan Boiteau
## Last update Sun Feb 26 23:38:53 2017 Ronan Boiteau
##

INC_DIR		= include/

CC		= gcc
CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra
CFLAGS		+= -Werror

RM		= rm -f

TOOLS_DIR	= src/tools/
TOOLS_FILES	= match.c			\
		  my_char_isprintable.c		\
		  my_strcmp.c			\
		  my_strdup.c			\
		  my_strlen.c
TOOLS		= $(addprefix $(TOOLS_DIR), $(TOOLS_FILES))

NM		= my_nm

NM_DIR		= src/nm/
NM_FILES	= main.c
NM_SRCS		= $(addprefix $(NM_DIR), $(NM_FILES))

NM_OBJS		= $(NM_SRCS:.c=.o)

OBJD		= my_objdump

OBJD_DIR	= src/objdump/
OBJD_FILES	= check_name.c			\
		  add_extra_spaces.c		\
		  main.c			\
		  objdump32.c			\
		  objdump64.c			\
		  error.c			\
		  print_content_hex.c
OBJD_SRCS	= $(addprefix $(OBJD_DIR), $(OBJD_FILES))
OBJD_SRCS	+= $(TOOLS)

OBJD_OBJS	= $(OBJD_SRCS:.c=.o)


all: nm objdump

nm: $(NM_OBJS)
	$(CC) -o $(NM) $(NM_OBJS)

objdump: $(OBJD_OBJS)
	$(CC) -o $(OBJD) $(OBJD_OBJS)

clean:
	$(RM) $(NM_OBJS) $(OBJD_OBJS)

fclean: clean
	$(RM) $(NM) $(OBJD)

re: fclean all

.PHONY: all clean fclean re
