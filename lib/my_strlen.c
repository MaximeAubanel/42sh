/*
** my_strlen.c for my_strlen in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:08:09 2016 Maxime Aubanel
** Last update Tue Apr 26 15:16:29 2016 Maxime Aubanel
*/

#include "lib.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}
