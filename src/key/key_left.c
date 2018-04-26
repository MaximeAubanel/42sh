/*
** key_left.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed May 11 14:32:06 2016 Maxime Aubanel
** Last update Wed May 11 14:53:10 2016 Maxime Aubanel
*/

#include "my.h"

void			key_left(t_data *data)
{
  int			x;
  int			y;

  getyx(data->ncurse.win, y, x);
  if (x >= 4)
    wmove(data->ncurse.win, y, x - 1);
}
