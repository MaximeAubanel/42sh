##
## Makefile for Makefile in /home/aubane_m/rendu/PSU_2015_minishell1
##
## Made by Maxime Aubanel
## Login   <aubane_m@epitech.net>
##
## Started on  Sun Jan 24 20:22:12 2016 Maxime Aubanel
## Last update Tue May 31 13:22:11 2016 deforges
##

all:
	make -C ./lib
	make -C ./src
	mv src/42sh .

clean:
	make clean -C ./lib
	make clean -C ./src

fclean:
	make fclean -C ./lib
	make fclean -C ./src

re: fclean all

.PHONY: all clean fclean re
