/*
** binary_tree_ext.c for binary_tree in /home/truchl_b/rendu/PSU/PSU_2015_42sh
** 
** Made by Bartosz Truchlewski
** Login   <truchl_b@epitech.net>
** 
** Started on  Sun Jun  5 16:50:27 2016 Bartosz Truchlewski
** Last update Sun Jun  5 16:59:44 2016 Bartosz Truchlewski
*/

#include "my.h"

void	find_token_ext(char *str, int *i)
{
  if (str[*i] == '"' || str[*i] == '\'' || str[*i] == '`')
    {
      *i += 1;
      while (str[*i] != '"' && str[*i] != '\'' && str[*i] != '`'
	     && str[*i] != '\0')
	*i += 1;
    }
}
