/*
** delete.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed May 11 21:34:21 2016 Maxime Aubanel
** Last update Thu May 12 14:23:45 2016 Maxime Aubanel
*/

#include "my.h"

char				*delete_char_cmd(t_data *data)
{
  char				*new;
  int				x;
  int				y;

  getyx(data->ncurse.win, y , x);
  y = 0;
  new = malloc(sizeof(char) * my_strlen(data->my_cmd.cmd));
  while (y != x - 3)
    {
      new[y] = data->my_cmd.cmd[y];
      y = y + 1;
    }
  y = y + 1;
  while (data->my_cmd.cmd[y])
    {
      new[y - 1] = data->my_cmd.cmd[y];
      y = y + 1;
    }
  new[y - 1] = '\0';
  return (new);
}

void				key_delete(t_data *data)
{
  int				x;
  int				y;
  (void)data;

  getyx(data->ncurse.win, y , x);
  if (x > 3)
    {
      move(y, x - 1);
      delch();
      data->my_cmd.cmd = delete_char_cmd(data);
    }
}
