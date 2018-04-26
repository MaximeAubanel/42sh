/*
** key_up.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed May 11 14:32:26 2016 Maxime Aubanel
** Last update Tue Jun 07 13:45:29 2016 Maxime Aubanel
*/

#include "my.h"

char			*history_search(t_data *data, int x)
{
  t_cmd			*current;

  current = data->cmd->head;
  while (current != NULL)
    {
      if (current->x == x)
	return (current->str);
      current = current->next;
    }
  return (NULL);
}

void			print_history_key(t_data *data, int y)
{
  char			*cmd;

  cmd = history_search(data, data->my_cmd.x);
  mvprintw(y, 3, cmd);
  data->my_cmd.cmd = cmd;
  wmove(data->ncurse.win, y, 3 + (my_strlen(cmd)));
}

void			key_up(t_data *data)
{
  int			x;
  int			y;

  (void)x;
  if (data->my_cmd.x > 1)
    {
      getyx(data->ncurse.win, y, x);
      if (data->my_cmd.cmd != NULL)
	{
	  x = 100;
	  while (x != 3)
	    {
	      delch();
	      move(y, x);
	      x = x - 1;
	    }
	}
      wmove(data->ncurse.win, y, 3);
      data->my_cmd.x = data->my_cmd.x - 1;
      print_history_key(data, y);
    }
}
