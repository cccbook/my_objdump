##
## Makefile for nm/objdump in /home/ronan/Documents/PSU_2016_nmobjdump
## 
## Made by Ronan Boiteau
## Login   <ronan.boiteau@epitech.net>
## 
## Started on  Tue Feb 21 00:29:21 2017 Ronan Boiteau
## Last update Tue Feb 21 00:33:38 2017 Ronan Boiteau
##

INC_DIR		= include/

CC		= gcc
CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra
CFLAGS		+= -Werror

RM		= rm -f

NM		= my_nm

NM_DIR		= src/nm/
NM_FILES	= main.c
NM_SRCS		= $(addprefix $(NM_DIR), $(NM_FILES))

NM_OBJS		= $(NM_SRCS:.c=.o)

OBJD		= my_objdump

OBJD_DIR	= src/objdump/
OBJD_FILES	= main.c
OBJD_SRCS	= $(addprefix $(OBJD_DIR), $(OBJD_FILES))

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