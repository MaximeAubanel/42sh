/*
** key_ctrl_a.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 12 14:43:16 2016 Maxime Aubanel
** Last update Wed Jun 01 23:16:04 2016 Maxime Aubanel
*/

#include "my.h"

void			key_ctrl_a(t_data *data)
{
  int			x;
  int			y;

  (void)x;
  reset_shell_mode();
  getyx(data->ncurse.win, y, x);
  move(y, 3);
  reset_prog_mode();
}
