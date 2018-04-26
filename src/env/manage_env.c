/*
** manage_env.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/env
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sat Jun 04 10:43:19 2016 Maxime Aubanel
** Last update Sat Jun  4 14:16:44 2016 Bartosz Truchlewski
*/

#include "my.h"

int			check_PATH(char **env, char *str)
{
  int			x;

  x = 0;
  while (env[x] != NULL && my_strncmp(env[x], str, 4) != 0)
      x = x + 1;
  return (x);
}

char			*HOME_to_str(char **env)
{
  int			x;
  int			y;
  char			*str;
  int			i;

  i = 0;
  str = malloc(sizeof(char) * 200);
  x = check_PATH(env, "HOME");
  y = 5;
  while (env[x][y] != '\0')
    {
      str[i] = env[x][y];
      i = i + 1;
      y = y + 1;
    }
  str[i] = '\0';
  return (str);
}

int			path_exist(char **env)
{
  int			x;

  x = 0;
  while (env[x])
    {
      if (my_strncmp(env[x], "PATH", 4) == 0)
	return (x);
      x = x + 1;
    }
  return (-1);
}

char			*PATH_to_str(char **env)
{
  int			x;
  int			y;
  char			*str;
  int			i;

  i = 0;
  str = malloc(sizeof(char) * 200);
  x = path_exist(env);
  if (x == -1)
    return (strdup("/usr/local/bin:/usr/bsd:/bin:/usr/bin"));
  y = 5;
  while (env[x][y] != '\0')
    {
      str[i] = env[x][y];
      i = i + 1;
      y = y + 1;
    }
  str[i] = '\0';
  return (str);
}

char			*getfieldenv(t_list *list, char *str)
{
  t_elem		*current;
  char			*str2;
  int			x;

  x = 0;
  current = list->head;
  while (current->next != NULL &&
	 my_strncmp(current->str, str, my_strlen(str)) != 0)
    {
      current = current->next;
      x = x + 1;
    }
  str2 = my_revstrncpy(current->str, my_strlen(str));
  return (str2);
}
