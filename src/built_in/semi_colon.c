/*
** semi_colon.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU_2015_42sh/src/built_in
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Sun Jun 05 07:18:09 2016 deforges
** Last update Sun Jun 05 08:03:59 2016 deforges
*/

#include "my.h"

int			semicolon(t_data *data, t_node *node)
{
  if (node && node->left)
    exectree(data, node->left);
  if (node && node->right)
    exectree(data, node->right);
  return (0);
}
