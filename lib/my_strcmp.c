/*
** my_strcmp.c for my_strcmp in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:09:59 2016 Maxime Aubanel
** Last update Thu May 12 15:00:16 2016 Maxime Aubanel
*/

#include "lib.h"

int			my_strcmp(char *cmp1, char *cmp2)
{
  int			i;

  i = 0;
  if (my_strlen(cmp1) != my_strlen(cmp2))
    return (1);
  while (cmp1[i] != '\0')
    {
      if (cmp1[i] != cmp2[i])
        return (1);
      if (cmp1[i] == '\0' && cmp2[i] != '\0')
	return (1);
      if (cmp2[i] == '\0' && cmp1[i] != '\0')
	return (1);
      i = i + 1;
    }
  return (0);
}
