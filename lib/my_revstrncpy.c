/*
** my_revstrncpy.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Apr 05 12:08:42 2016 Maxime Aubanel
** Last update Sat Jun  4 00:55:10 2016 deforges
*/

#include "lib.h"

char			*my_revstrncpy(char *str, int i)
{
  char			*new;
  int			x;

  x = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) - i + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[x] = str[i];
      i = i + 1;
      x = x + 1;
    }
  new[x] = '\0';
  return (new);
}
