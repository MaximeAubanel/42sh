/*
** SETENV_UNSETENV.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Apr 05 12:11:26 2016 Maxime Aubanel
** Last update Tue Jun 07 13:10:05 2016 Maxime Aubanel
*/

#include "my.h"

void			modif_setenv(t_data *data, int x)
{
  char			*str;

  if ((str = malloc(sizeof(char) * 100)) == NULL)
      return ;
  my_strcpy(str, data->exec.arg[1]);
  my_strcat(str, "=");
  if (data->exec.arg[2] != NULL)
    my_strcat(str, data->exec.arg[2]);
  else
    my_strcat(str, "\0");
  change_list(&data->my_list, str, x - 2);
}

int			check_next(t_data *data, t_elem *elem)
{
  if (elem->next == NULL)
    {
      kill(data->pid_f, SIGUSR1);
      my_putstr("Not Found\n");
      return (0);
    }
  return (-1);
}

void			my_unsetenv(t_data *data, char *str)
{
  t_elem		*current;
  int			x;
  int			i;

  i = 0;
  if (str != NULL)
    {
      while (data->exec.arg[++i])
	{
	  x = 0;
          current = data->my_list.head;
	  while (my_strncmp(current->str, data->exec.arg[i], my_strlen(str)) != 0)
	    {
	      if (check_next(data, current) == 0)
		return ;
	      current = current->next;
	      x = x + 1;
	    }
	  delete_list(&data->my_list, x);
	}
      return ;
    }
  my_putstr("unsetenv need at least one parameter\n");
}

void			my_setenv(t_data *data, char *str)
{
  int			value;

  (void)str;
  value = 0;
  if (data->exec.arg[1] == NULL)
    {
      my_env(data, str);
      return ;
    }
  if ((value = check_env_exist(data, &data->my_list, data->exec.arg[1])) == -1)
    {
      if (data->exec.arg[2] == NULL)
	new_env_null(data);
      else
	new_env(data);
    }
  else if (value == 1)
    return ;
  else
    modif_setenv(data, check_env_exist
		 (data, &data->my_list, data->exec.arg[1]));
}
