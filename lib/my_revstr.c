/*
** my_revstr.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Apr 08 10:54:34 2016 Maxime Aubanel
** Last update Sat Jun  4 00:54:40 2016 deforges
*/

#include "lib.h"

char			*my_revstr(char *str)
{
  char			*new;
  int			i;
  int			x;

  x = 0;
  i = my_strlen(str) - 1;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (i >= 0)
    {
      new[x] = str[i];
      i = i - 1;
      x = x + 1;
    }
  new[x] = '\0';
  return (new);
}
