/*
** key_ctrl_l.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 12 15:24:52 2016 Maxime Aubanel
** Last update Wed Jun 01 23:14:56 2016 Maxime Aubanel
*/

#include "my.h"

void			key_ctrl_l(t_data *data)
{
  (void)data;
  reset_shell_mode();
  system("clear");
  my_putstr("$->");
  if (data->my_cmd.cmd != NULL)
    my_putstr(data->my_cmd.cmd);
  reset_prog_mode();
}
