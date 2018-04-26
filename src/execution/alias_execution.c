/*
** alias_execution.c for PSU_2015_42sh in /home/aubane_m/rendu/Tek1/PSU/PSU_2015_42sh/src/execution
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Jun 07 13:03:15 2016 Maxime Aubanel
** Last update Tue Jun 07 16:26:26 2016 Maxime Aubanel
*/

#include "my.h"

int			check_if_alias(t_data *data, char *cmd)
{
  int			i;
  char			**tab;

  tab = str_to_wordtab(cmd);
  i = 0;
  if (data->bashrc_ex != 0)
    {
      while (data->bashrc.alias[i].alias)
	{
	  if (my_strncmp(data->bashrc.alias[i].alias, tab[0],
		 my_strlen(data->bashrc.alias[i].alias)) == 0)
	    return (i);
	  i = i + 1;
	}
    }
  return (-1);
}

int			check_if_alias2(t_data *data, char *cmd)
{
  int			i;
  char			**tab;

  tab = str_to_wordtab(cmd);
  i = 0;
  if (data->bashrc_ex != 0)
    {
      while (data->bashrc.alias[i].alias)
	{
	  if (my_strncmp(data->bashrc.alias[i].cmd, tab[0],
		 my_strlen(data->bashrc.alias[i].cmd)) == 0)
	    return (i);
	  i = i + 1;
	}
    }
  return (-1);
}


char			**check_alias(t_data *data, char **tab, int x)
{
  char			**new;
  int			i;

  i = 0;
  while (tab[i])
    i = i + 1;
  new = malloc(sizeof(char*) * (i + 2));
  i = 0;
  while (tab[i])
    {
      new[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
      new[i] = my_strcpy(new[i], tab[i]);
      i = i + 1;
    }
  new[i] = data->bashrc.alias[x].param;
  new[i + 1] = NULL;
  return (new);
}


void			check_alias_exec(t_data *data)
{
  if (check_if_alias(data, data->exec.arg[0]) != -1)
    data->exec.arg = check_alias(data, data->exec.arg,
				 check_if_alias2(data, data->exec.arg[0]));
}
