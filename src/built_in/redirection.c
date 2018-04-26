/*
** redirection.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon Apr 11 13:35:03 2016 Maxime Aubanel
** Last update Tue Jun 07 13:01:48 2016 Maxime Aubanel
*/

#include "my.h"

void			exec_redir_right(t_data *data, t_node *node)
{
  pid_t			pid;

  if ((pid = fork()) == 0)
    {
      dup2(data->dup.redirect, 1);
      exectree(data, node);
      exit (0);
    }
  else
    {
      wait(&pid);
      close(data->dup.redirect);
    }
}

int			simple_redir_right(t_data *data, t_node *node)
{
  if (node && node->right && node->right->data != NULL)
    {
      if ((data->dup.redirect =
	   open(node->right->data, O_WRONLY | O_CREAT
		| O_TRUNC, S_IWUSR | S_IRUSR)) == -1)
	{
	  kill(data->pid_f, SIGUSR1);
	  my_putstr(node->right->data);
	  my_putstr(": No such file or directory\n");
	  return (0);
	}
      exec_redir_right(data, node->left);
      data->dup.mode += 1;
    }
  else
    {
      kill(data->pid_f, SIGUSR1);
      my_putstr("Missing name for redirect\n");
    }
  return (0);
}

int			double_redir_right(t_data *data, t_node *node)
{
  if (node && node->right && node->right->data != NULL)
    {
      if ((data->dup.redirect =
	   open(node->right->data, O_WRONLY | O_CREAT
		| O_APPEND, S_IWUSR | S_IRUSR)) == -1)
	{
	  kill(data->pid_f, SIGUSR1);
	  my_putstr(node->right->data);
	  my_putstr(": No such file or directory\n");
	  return (0);
	}
      exec_redir_right(data, node->left);
      data->dup.mode += 1;
    }
  else
    {
      kill(data->pid_f, SIGUSR1);
      my_putstr("Missing name for redirect\n");
    }
  return (0);
}

void			exec_redir_left(t_data *data, t_node *node)
{
  pid_t			pid;

  if ((pid = fork()) == 0)
    {
      dup2(data->dup.indirect, 0);
      exectree(data, node);
      exit (0);
    }
  else
    {
      wait(&pid);
      close(data->dup.indirect);
    }
}

int			simple_redir_left(t_data *data, t_node *node)
{
  if (node && node->right && node->right->data != NULL)
    {
      if ((data->dup.indirect =
	   open(node->right->data, O_RDWR | O_CREAT)) == -1)
	{
	  kill(data->pid_f, SIGUSR1);
	  my_putstr(node->right->data);
	  my_putstr(": No such file or directory\n");
	  return (0);
	}
      exec_redir_left(data, node->left);
      data->dup.mode += 1;
    }
  else
    {
      kill(data->pid_f, SIGUSR1);
      my_putstr("Missing name for redirect\n");
    }
  return (0);
}
