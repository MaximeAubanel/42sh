/*
** manage_env_ext.c for manage_env in /home/truchl_b/rendu/PSU/PSU_2015_42sh
**
** Made by Bartosz Truchlewski
** Login   <truchl_b@epitech.net>
**
** Started on  Sat Jun  4 14:15:36 2016 Bartosz Truchlewski
** Last update Sat Jun 04 22:45:52 2016 Maxime Aubanel
*/

#include "my.h"

char		*check_access(char **tab)
{
  int		i;
  char		*str;

  str = NULL;
  i = 0;
  while (tab[i] != NULL)
    {
      if (access(tab[i], F_OK) == 0 && access(tab[i], X_OK) == 0)
        str = tab[i];
      i = i + 1;
    }
  return (str);
}
