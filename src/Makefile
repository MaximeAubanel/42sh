##
## Makefile for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
##
## Made by Maxime Aubanel
## Login   <aubane_m@epitech.net>
##
## Started on  Thu Mar 17 17:47:03 2016 Maxime Aubanel
## Last update Sun Jun  5 21:18:31 2016 Bartosz Truchlewski
##

RM	= rm -f

CC	= gcc -g3

CFLAGS  += -W -Wall -Wextra
CFLAGS  += -I./../include/

LIB = -L./../lib/ -lmy -lncurses

SRC	= main.c \
		  isatty.c \
			list/double_list.c \
			list/simple_list.c \
			list/simple_list_tools.c \
			time/time.c \
			env/manage_env.c \
			env/manage_env_ext.c \
			display_error.c \
			execution/execution.c \
			execution/alias_execution.c \
			built_in/pipe.c \
			built_in/redirection.c \
			built_in/semi_colon.c \
			built_in/exclamation_mark/event_mark.c \
			built_in/exclamation_mark/get_pos_history.c \
			built_in/exclamation_mark/get_cmd_history.c \
			built_in/exclamation_mark/all_check.c \
			binary_tree/exec_tree.c \
			binary_tree/binary_tree.c \
			binary_tree/binary_tree_ext.c \
			built_in/and_or.c \
			tools/str_tools.c \
			tools/tab_tools.c \
			ncurse/ncurse.c \
			ncurse/init_ncurse.c \
			ncurse/my_cmd.c \
			ncurse/ncurse_tools.c \
			ncurse/exec_cmd_ncurse.c \
			ncurse/init_bashrc.c \
			built_in/basic/cd.c \
			built_in/basic/echo/back_slash.c \
			built_in/basic/echo/nrm.c \
			built_in/basic/echo/help.c \
			built_in/basic/echo/echo.c \
			built_in/basic/echo/glob.c \
			built_in/basic/echo/h_echo.c \
			built_in/basic/echo/fun.c \
			built_in/basic/echo/match.c \
			built_in/basic/exit_env.c \
			built_in/basic/env_modification_CD.c \
			built_in/basic/SETENV_UNSETENV.c \
			built_in/basic/modif_env_SETENV_UNSETENV.c \
			key/key_right.c \
			key/key_left.c \
			key/key_up.c \
			key/key_down.c \
			key/key_delete.c \
			key/key_ctrl_a.c \
			key/key_ctrl_y.c \
			key/key_ctrl_k.c \
			key/key_ctrl_e.c \
			key/key_ctrl_d.c \
			key/key_ctrl_l.c \
			key/key_tab.c \
			key/key_tab_ext1.c \
			key/key_tab_ext2.c \
			key/key_parser.c \

OBJ	= $(SRC:.c=.o)

NAME	= 42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ)  $(LIB) -o $(NAME)

clean:
	 $(RM) $(OBJ)

fclean: clean
	  $(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
