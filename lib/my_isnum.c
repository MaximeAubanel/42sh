/*
** my_isnum.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/lib
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Sat Jun 04 05:27:12 2016 deforges
** Last update Sat Jun 04 17:09:28 2016 deforges
*/

#include <stdio.h>
#include "lib.h"

int		my_isnum(char *str)
{
  int		i;

  i = 0;
  while (str && str[++i])
    {
      if (str[i] != '-' && str[i] < 48 && str[i] > 57)
	return (-1);
    }
  return (0);
}
