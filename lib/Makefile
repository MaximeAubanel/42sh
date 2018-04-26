##
## Makefile for Makefile in /home/aubane_m/rendu/PSU_2015_minishell1/lib
##
## Made by Maxime Aubanel
## Login   <aubane_m@epitech.net>
##
## Started on  Sun Jan 24 20:37:07 2016 Maxime Aubanel
## Last update Sat Jun  4 05:25:33 2016 deforges
##

RM	= rm -f

CC	= gcc

SRC	= my_putchar.c \
	  my_putstr.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  my_strlen.c \
	  get_next_line.c \
	  my_strcpy.c \
	  str_to_wordtab.c \
	  my_bzero.c \
	  my_strncpy.c \
		my_revstrncpy.c \
		my_revstr.c \
		my_getnbr.c \
		my_isnum.c

CFLAGS += -W -Wall -Werror -Wextra -I./../include/ ${DEV_CFLAG_GDB} ${DEV_CFLAG_VAL} -g3

CFLAGS += -I.my.h

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	 $(RM) $(OBJ)

fclean: clean
	  $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
