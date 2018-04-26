/*
** my_strcat.c for my_strcat in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:09:07 2016 Maxime Aubanel
** Last update Sat Jun 04 02:55:53 2016 Maxime Aubanel
*/

#include "lib.h"
#include "stdio.h"
char			*my_strcat(char *dest, char *src)
{
  int x;
  int i;
  char			*new;

  if ((new = malloc(sizeof(char) *
		    (my_strlen(dest) + (my_strlen(src)) + 1))) == NULL)
    return (NULL);
  x = my_strlen(dest);
  i = 0;
  while (i != x)
    {
      new[i] = dest[i];
      i = i + 1;
    }
  i = 0;
  while (src[i])
    {
      dest[x + i] = src[i];
      i = i + 1;
    }
  dest[x + i] = '\0';
  return (dest);
}
