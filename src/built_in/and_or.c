/*
** and_or.c for 42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/src
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Fri May 27 16:46:15 2016 deforges
** Last update Wed Jun 01 17:02:00 2016 Maxime Aubanel
*/

#include "my.h"

bool		check_exec;

void		check_exec_error(int signum)
{
  (void)signum;
  check_exec = true;
}

int		and(t_data *data, t_node *node)
{
  check_exec = false;
  if (node && node->left)
    exectree(data, node->left);
  if (check_exec == true)
    return (-1);
  if (node && node->right && data->status == 0)
    exectree(data, node->right);
  return (0);
}

int		or(t_data *data, t_node *node)
{
  check_exec = false;
  if (node && node->left)
    exectree(data, node->left);
  if (data->status != 0 || check_exec == true)
    if (node && node->right)
      exectree(data, node->right);
  return (0);
}
