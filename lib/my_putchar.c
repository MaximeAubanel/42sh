/*
** my_puchar.c for my_putchar in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:06:06 2016 Maxime Aubanel
** Last update Sat Jun  4 00:53:29 2016 deforges
*/

#include "lib.h"

void			my_putchar(char c)
{
  if (write (1, &c, 1) == -1)
    return ;
}
