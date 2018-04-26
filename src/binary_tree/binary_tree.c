/*
** binary_tree.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Apr 08 16:24:18 2016 Maxime Aubanel
** Last update Sun Jun  5 21:24:26 2016 Bartosz Truchlewski
*/

#include "my.h"

int	find_prior(char *str, int *pos)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_strncmp(str + i, ";", my_strlen(";")) == 0)
	{
	  *pos = i;
	  return (0);
	}
      i = i + 1;
    }
  return (-1);
}

char			*find_token(char *str, int *pos)
{
  int			i;
  char			*token[] = {"&&", "||", "|", ">", "<", ">>", "<<", NULL};
  int			x;

  x = 5;
  if (find_prior(str, pos) == 0)
    return (";");
  while (x > -1)
    {
      i = 0;
      find_token_ext(str, &i);
      while (str[i] != '\0')
	{
	  if (my_strncmp(str + i, token[x], my_strlen(token[x])) == 0)
	    {
	      *pos = i;
	      return (token[x]);
	    }
	  i = i + 1;
	}
      x = x - 1;
    }
  return (NULL);
}

char			*my_strdup(char *str)
{
  char			*new;
  int			nb;
  int			i;

  i = 0;
  nb = my_strlen(str);
  if (nb > 0)
    {
      if ((new = malloc(sizeof(char) * (nb + 1))) == NULL)
	return (NULL);
      new[nb] = '\0';
      while (str[i] != '\0')
	{
	  new[i] = str[i];
	  i = i + 1;
	}
      return (new);
    }
  return NULL;
}

t_node			*setnode()
{
  t_node		*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->data = NULL;
  new->right = NULL;
  new->left = NULL;
  return (new);
}

t_node			*build_tree(char *str)
{
  t_node		*node;
  char			*op;
  int			pos;

  node = setnode();
  if ((op = find_token(str, &pos)) != NULL)
    {
      node->data = my_strdup(op);
      str[pos] = '\0';
      if (my_strlen(op) > 1)
	{
	  str[pos + 1] = '\0';
	  node->left = build_tree(str);
	  node->right = build_tree(str + pos + 2);
	}
      else
	{
	  node->left = build_tree(str);
      	  node->right = build_tree(str + pos + 1);
	}
    }
  else
    node->data = my_strdup(str);
  node->data = normalize_str(node->data);
  return (node);
}
