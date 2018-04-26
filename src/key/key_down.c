/*
** key_down.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed May 11 14:32:16 2016 Maxime Aubanel
** Last update Fri Jun 03 22:08:18 2016 deforges
*/

#include "my.h"

void			key_down(t_data *data)
{
  int			x;
  int			y;

  (void)x;
  if (data->my_cmd.x < data->my_cmd.nb)
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
      if (data->my_cmd.x != data->nb)
	data->my_cmd.x = data->my_cmd.x + 1;
      print_history_key(data, y);
    }
}
