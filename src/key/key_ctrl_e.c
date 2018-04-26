/*
** key_ctrl_e.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 12 14:43:25 2016 Maxime Aubanel
** Last update Mon May 23 13:57:11 2016 Maxime Aubanel
*/

#include "my.h"

void			key_ctrl_e(t_data *data)
{
  int			x;
  int			y;

  getyx(stdscr, y, x);
  reset_shell_mode();
  if (x >= 3 && data->my_cmd.cmd != NULL)
    {
      x = my_strlen(data->my_cmd.cmd);
      move(y, x + 3);
    }
    reset_prog_mode();
}
