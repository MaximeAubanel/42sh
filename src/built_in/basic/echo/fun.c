/*
** fun.c for  in /home/aubane_m/rendu/Tek1/PSU/PSU_2015_42sh
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Jun  7 14:38:20 2016 Maxime Aubanel
** Last update Tue Jun  7 14:44:58 2016 Maxime Aubanel
*/

#include "my.h"

int	*my_init_var(int val)
{
  int	*res;
  int	i;

  if ((res = malloc(sizeof(int) * val)) == NULL)
    return (NULL);
  i = -1;
  while (++i < val)
    res[i] = 0;
  return (res);
}
