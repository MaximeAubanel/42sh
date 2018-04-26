/*
** key_down.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed May 11 14:21:38 2016 Maxime Aubanel
** Last update Wed May 11 21:47:14 2016 Maxime Aubanel
*/

#include "my.h"

void			key_right(t_data *data)
{
  int			x;
  int			y;

  getyx(data->ncurse.win, y, x);
  if (data->my_cmd.cmd != NULL && x <= my_strlen(data->my_cmd.cmd) + 2)
    wmove(data->ncurse.win, y, x + 1);
}
