/*
** exececution.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Mar 25 16:27:58 2016 Maxime Aubanel
** Last update Tue Jun 07 16:23:28 2016 Maxime Aubanel
*/

#include "my.h"

t_buildin		build[] = {
  {"env", &my_env},
  {"history", &my_history},
  {"setenv", &my_setenv},
  {"unsetenv", &my_unsetenv},
  {"cd", &my_cd},
  {"exit", &my_exit},
  {"echo", &my_echo},
  {NULL, NULL}
};

void			check_return_exec(t_data *data, int status)
{
  if (status > 0)
    data->my_exit = 1;
  if (status == 0)
    data->my_exit = 0;
}

int			check_char_exec(char c)
{
  if (c == '/' || c == '~' || c == '.')
    return (0);
  return (-1);
}

int			exec_fork(t_data *data)
{
  check_alias_exec(data);
  if (data->exec.access == NULL)
    return (-1);
  if (execve(data->exec.access, data->exec.arg, data->exec.env) == -1)
    return (-1);
  return (0);
}

int			function_fork(t_data *data)
{
  pid_t			pid;

  data->status = 0;
  signal(SIGUSR1, check_exec_error);
  data->pid_f = getpid();
  if ((pid = fork()) == 0)
    {
      data->exec.env = list_in_chartab(&data->my_list);
      if (check_char_exec(data->exec.cmd_nrml[0]) == 0)
	{
	  if ((execve(data->exec.arg[0], data->exec.arg, data->exec.env)) == -1)
	    return (-1);
	}
      else
	return (exec_fork(data));
    }
  else
    waitpid(pid, &data->status, 0);
  check_return_exec(data, data->status);
  return (0);
}

void			execution(t_data *data)
{
  int			i;
  int			x;

  x = 0;
  i = -1;
  reset_shell_mode();
  while (build[++i].str)
    {
      if (my_strcmp(build[i].str, data->exec.arg[0]) == 0)
	{
	  build[i].action(data, data->exec.arg[1]);
	  x = 1;
	}
    }
  if (x == 0 && function_fork(data) != 0)
    {
      my_putstr(data->exec.arg[0]);
      my_putstr(": Command not found.\n");
      exit (1);
      kill(data->pid_f, SIGUSR1);
    }
  data->dup.indirect = -1;
  data->dup.redirect = -1;
  data->dup.mode = 0;
}
