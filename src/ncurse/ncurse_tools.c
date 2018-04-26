/*
** my_prompt.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Jun 03 18:52:16 2016 Maxime Aubanel
** Last update Sun Jun  5 13:39:16 2016 Bartosz Truchlewski
*/

#include "my.h"

void			my_backspace()
{
  int			x;
  int			y;

  (void)x;
  (void)y;
  refresh();
  getyx(curscr, y, x);
  move(y + 1, 0);
  refresh();
}

void			my_prompt_ncurse(t_data *data, my_ncurse *ncurse)
{
  int			x;
  int			y;

  (void)x;
  (void)y;
  if (data->my_cmd.cmd == NULL)
    my_backspace();
  getyx(ncurse->win, y, x);
  data->my_cmd.cmd = NULL;
  mvwprintw(ncurse->win, y, 0, "$->");
}
