/*
** init_ncurse.c for le42 in /home/aubane_m/rendu/PSU/le42/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 23 13:59:35 2016 Maxime Aubanel
** Last update Sat Jun 04 10:20:39 2016 Maxime Aubanel
*/

#include "my.h"

void			init_ncurse(t_data *data, my_ncurse *ncurse)
{
  def_shell_mode();
  init_bashrc(data);
  ncurse->win = initscr();
  scrollok(ncurse->win, TRUE);
  noecho();
  keypad(ncurse->win, true);
  mvwprintw(ncurse->win, 0, 0, "$->");
  data->my_cmd.cmd = NULL;
  data->copy = NULL;
}
