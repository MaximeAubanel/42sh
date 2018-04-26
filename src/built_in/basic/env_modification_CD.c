/*
** env_modification_CD.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 13:25:50 2016 Maxime Aubanel
** Last update Sun Jun 05 11:29:05 2016 deforges
*/

#include "my.h"

void			modif_oldpwd(t_data *data)
{
  t_elem		*current;
  int			x;
  char			*pwd;
  char			*tmp;

  if ((tmp = malloc(sizeof(char) * 100)) == NULL)
    return ;
  pwd = NULL;
  pwd = getcwd(NULL, 100);
  my_strcpy(tmp, "PWD=");
  current = data->my_list.head;
  x = 0;
  while (current->next != NULL && (my_strncmp(current->str, "PWD=", 3) != 0))
    {
      current = current->next;
      x = x + 1;
    }
  my_strcat(tmp, pwd);
  if (tmp != NULL)
    data->env.pwd = my_revstrncpy(tmp, 4);
  change_list(&data->my_list, tmp, x - 1);
}

void			modif_pwd(t_data *data, char *oldpwd)
{
  t_elem		*current;
  int			x;
  char			*tmp;

  if ((tmp = malloc(sizeof(char) * 100)) == NULL)
    return ;
  my_strcpy(tmp, "OLDPWD=");
  my_strcat(tmp, oldpwd);
  x = 0;
  current = data->my_list.head;
  while (current->next != NULL
	 && (my_strncmp(current->str, "OLDPWD=", 6) != 0))
    {
      current = current->next;
      x = x + 1;
    }
  if (tmp != NULL)
    data->env.oldpwd = my_revstrncpy(tmp, 7);
  change_list(&data->my_list, tmp, x - 1);
}

int			check_env_exist(t_data *data, t_list *list, char *str)
{
  t_elem		*current;
  int			x;

  (void)data;
  current = list->head;
  x = 0;
  while (current != NULL)
    {
      if (my_strncmp(current->str, str, my_strlen(str)) == 0)
	return (x + 1);
      current = current->next;
      x = x + 1;
    }
  return (-1);
}

void			modif_env_cd(t_data *data, char *oldpwd)
{
  if (check_env_exist(data, &data->my_list, "OLDPWD=") != -1)
    modif_oldpwd(data);
  if (check_env_exist(data, &data->my_list, "PWD=") != -1)
    modif_pwd(data, oldpwd);
}
