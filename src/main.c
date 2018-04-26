/*
** main.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Jun 01 22:25:03 2016 Maxime Aubanel
** Last update Tue Jun 07 12:52:27 2016 Maxime Aubanel
*/

#include <ncurses.h>
#include <curses.h>
#include <sys/ioctl.h>
#include "my.h"
#include "error.h"

void			initialization_struct(t_data *data, char **env)
{
  data->my_list = *tab_in_list(&data->my_list, env);
  data->dup.mode = 0;
  data->nb = 0;
  data->mark = true;
  data->isnum = true;
  data->mark_alone = false;
  data->my_cmd.x = 0;
  data->my_cmd.nb = 0;
  data->dup.indirect = -1;
  data->dup.redirect = -1;
  data->my_exit = 0;
  data->exec.env = env;
  data->env.pwd = getfieldenv(&data->my_list, "PWD=");
  init_list_double(&data->cmd);
}

void			launch_42sh_shell(t_data *data)
{
  init_bashrc(data);
  while ((data->my_cmd.cmd = get_next_line(0)) != NULL)
    {
      data->my_exit = 0;
      data->my_cmd.cmd = normalize_str(data->my_cmd.cmd);
      my_cmd_exec(data, &data->ncurse);
    }
  exit (data->my_exit);
}

void			launch_42sh(t_data *data, char **env)
{
  initialization_struct(data, env);
  if (isatty(0))
    lauch_42sh_ncurse(data, &data->ncurse);
  else
    launch_42sh_shell(data);
}

int			main(int ac, char **av, char **env)
{
  t_data		data;

  if (ac > 1 && av)
    return (display_error(&data, NO_PARAM));
  else if (env[0] != NULL && ac == 1)
    {
      launch_42sh(&data, env);
      return (0);
    }
  else
    return (-1);
  return (0);
}
