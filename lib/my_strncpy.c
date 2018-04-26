/*
** my_strncpy.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Mar 18 17:58:09 2016 Maxime Aubanel
** Last update Tue Apr 26 15:16:39 2016 Maxime Aubanel
*/

#include "lib.h"

char			*my_strncpy(char *dest, char *src, int n)
{
  int			i;

  i = 0;

  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}
