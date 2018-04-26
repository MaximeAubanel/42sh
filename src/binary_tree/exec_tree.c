/*
** exec_tree.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 13:36:21 2016 Maxime Aubanel
** Last update Tue Jun 07 13:01:51 2016 Maxime Aubanel
*/

#include "my.h"

void			 check_dup(t_data *data)
{
  if (data->dup.mode == -1)
    return ;
  if (data->dup.mode == 1)
    dup2(data->dup.redirect, 1);
  if (data->dup.mode == 2)
    dup2(data->dup.indirect, 0);
  if (data->dup.mode == 3)
    {
      dup2(data->dup.redirect, 1);
      dup2(data->dup.indirect, 0);
    }
}

tokenPtr arrayToken[] =
{
{";", &semicolon},
{"&&", &and},
{"||", &or},
{">", &simple_redir_right},
{">>", &double_redir_right},
{"<", &simple_redir_left},
{"|", &my_pipe},
{NULL, NULL}
};

int			exectree(t_data *data, t_node *node)
{
  int i;

  i = 0;
  if (node && node->right == NULL && node->right == NULL && node->data != NULL)
    {
      if (my_init(data, node->data) == -1)
	return (-1);
      execution(data);
    }
  while (node && node->data && arrayToken[i].flag)
    {
      if (my_strcmp(arrayToken[i].flag, node->data) == 0)
	arrayToken[i].fct(data, node);
      i = i + 1;
    }
  return (0);
}
