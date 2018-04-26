/*
** my_putstr.c for my_putstr in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:07:10 2016 Maxime Aubanel
** Last update Tue Apr 26 15:18:08 2016 Maxime Aubanel
*/

#include "lib.h"

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
