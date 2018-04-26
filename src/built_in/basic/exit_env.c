/*
** exit_env.c for le42 in /home/aubane_m/rendu/PSU/le42/src/built_in/basic
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue May 10 11:14:11 2016 Maxime Aubanel
** Last update Sun Jun 05 09:50:46 2016 deforges
*/

#include "my.h"

void			my_cd(t_data *data, char *str)
{
  (void)str;
  build_cd(data);
}

void			my_pimp_exit()
{
  int			x;

  x = -1;
  while (++x <= 10)
    {
      flash();
      if (usleep(100000) == -1)
	return ;
      printf("%d\n", 10 - x);
    }
  printf("See you bro :)\n");
  exit (0);
}

void			my_exit(t_data *data, char *str)
{
  (void)str;
  (void)data;
  if (isatty(0))
    wprintw(data->ncurse.win, "exit\n");
  else
    my_putstr("exit\n");
  if (data->exec.arg[1] != NULL && my_strcmp(data->exec.arg[1], "pimp") == 0)
    my_pimp_exit();
  if (data->exec.arg[1] != NULL)
    exit (atoi(data->exec.arg[1]) % 256);
  else
    {
      reset_shell_mode();
      exit (1);
    }
}

void			my_env(t_data *data, char *str)
{
  (void)str;
  reset_shell_mode();
  display_list(&data->my_list);
  reset_prog_mode();
}
