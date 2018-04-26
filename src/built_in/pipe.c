/*
** pipe.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 13:57:22 2016 Maxime Aubanel
** Last update Sun Jun  5 12:03:44 2016 Bartosz Truchlewski
*/

#include "my.h"

int	my_pipe_next(t_pid forkpid, int *pipefd, t_node *node, t_data *data)
{
  close(pipefd[1]);
  if ((forkpid.pid2 = fork()) == -1)
    return (-1);
  if (forkpid.pid2 == 0)
    {
      dup2(pipefd[0], 0);
      if (node && node->right && node->right->data != NULL)
	exectree(data, node->right);
      close(pipefd[0]);
      exit(1);
    }
  wait(&forkpid.status);
  return (1);
}

int	my_pipe(t_data *data, t_node *node)
{
  int	pipefd[2];
  int	error;
  t_pid	forkpid;

  reset_shell_mode();
  if ((error = pipe(pipefd)) == -1)
    return (-1);
  if ((forkpid.pid1 = fork()) == -1)
    return (-1);
  if (forkpid.pid1 == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      if (node && node->left && node->left->data != NULL)
	exectree(data, node->left);
      data->my_exit = 1;
      close(pipefd[1]);
      exit(1);
    }
  else
    if (my_pipe_next(forkpid, pipefd, node, data) == - 1)
      return (-1);
  reset_prog_mode();
  return (1);
}
