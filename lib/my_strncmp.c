/*
** my_strncmp.c for my_strncmp in /home/aubane_m/rendu/PSU_2015_minishell1/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Jan 24 20:10:32 2016 Maxime Aubanel
** Last update Sat Jun 04 03:33:22 2016 Maxime Aubanel
*/

#include "lib.h"

int			my_strncmp(char *cmp1, char *cmp2, int nb)
{
  int			i;

  i = 0;
  while ((cmp1[i] != '\0'|| cmp2[i] != '\0') && i < nb)
    {
      if (cmp1[i] > cmp2[i])
	return (1);
      if (cmp1[i] < cmp2[i])
        return (-1);
      i = i + 1;
    }
  return (0);
}
