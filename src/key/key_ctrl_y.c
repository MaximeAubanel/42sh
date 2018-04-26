/*
** ctrl_y.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Jun 01 23:03:12 2016 Maxime Aubanel
** Last update Thu Jun 02 16:53:41 2016 Maxime Aubanel
*/

#include "my.h"

char			*insert_in_str(char *cmd, char *str, int x)
{
  char			*new;
  int			i;
  int			j;

  i = -1;
  new = malloc(sizeof(char) * (my_strlen(str) + my_strlen(cmd) + 1));
  while (cmd[++i] && i <= x)
    new[i] = cmd[i];
  new[i] = '\0';
  new = my_strcat(new, str);
  j = my_strlen(new);
  while (cmd[++i])
    new[j] = cmd[i];
  new[j] = '\0';
  return (new);
}

void			key_ctrl_y(t_data *data)
{
  int			y;
  int			x;
  char			*str;

  getyx(data->ncurse.win, y, x);
  if (data->copy != NULL)
    {
      str = normalize_str(data->copy);
      insnstr(str, my_strlen(data->copy) - 1);
      if (data->my_cmd.cmd == NULL)
	data->my_cmd.cmd = data->copy;
      else
	data->my_cmd.cmd = insert_in_str(data->my_cmd.cmd, str, x - 3);
      data->my_cmd.cmd = normalize_str(data->my_cmd.cmd);
      move(y, my_strlen(data->my_cmd.cmd) + 3);
    }
}
