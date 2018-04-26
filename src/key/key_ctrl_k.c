/*
** ctrl_k.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Jun 01 23:03:15 2016 Maxime Aubanel
** Last update Thu Jun 02 17:37:32 2016 Maxime Aubanel
*/

#include "my.h"

char			*del_end_str(char *str, int x)
{
  char			*new;

  if (x == 0)
    return (NULL);
  new = malloc(sizeof(char) * (x + 1));
  new = my_strncpy(new, str, x);
  return (new);
}

void			key_ctrl_k(t_data *data)
{
  int			x;
  int			y;
  int			nb;

  nb = 0;
  getyx(data->ncurse.win, y, x);
  (void)y;
  if (data->my_cmd.cmd != NULL)
    {
      data->copy = malloc(sizeof(char) * 1000);
      innstr(data->copy, 1000);
      while (nb != 100)
	{
	  delch();
	  nb = nb + 1;
	}
      data->my_cmd.cmd = del_end_str(data->my_cmd.cmd, x - 3);
      return ;
    }
}
