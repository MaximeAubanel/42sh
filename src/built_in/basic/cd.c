/*
** cd.c for le42 in /home/aubane_m/rendu/PSU/le42/src/built_in/basic
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue May 10 11:13:02 2016 Maxime Aubanel
** Last update Sun Jun 05 08:05:01 2016 deforges
*/

#include "my.h"

void			cd_to_home(t_data *data)
{
  char			*home;

  home = HOME_to_str(data->exec.env);
  chdir(home);
  modif_env_cd(data, data->env.pwd);
  modif_env_cd(data, data->env.oldpwd);
}

void			cd_to_back(t_data *data)
{
  if ((chdir(data->env.oldpwd)) == -1)
    {
      kill(data->pid_f, SIGUSR1);
      my_putstr("OLDPWD not set\n");
    }
  else
    modif_env_cd(data, data->env.pwd);
}

void			cd_to_file(t_data *data)
{
  char			*old_pwd;

  old_pwd = NULL;
  old_pwd = getcwd(old_pwd, 100);
  if (access(data->exec.arg[1], F_OK) == -1)
    {
      my_putstr(data->exec.arg[1]);
      my_putstr(": No such file or directory\n");
      data->my_exit = 1;
    }
  else if (chdir(data->exec.arg[1]) != 0)
    {
      my_putstr(data->exec.arg[1]);
      kill(data->pid_f, SIGUSR1);
      if (access(data->exec.arg[1], R_OK) != -1)
	my_putstr(": Not a directory.\n");
      else
	my_putstr(": Permission denied.\n");
        data->my_exit = 1;
    }
  else
    modif_env_cd(data, old_pwd);
}

void			build_cd(t_data *data)
{
  if (data->exec.arg[1] == NULL)
    cd_to_home(data);
  else if (data->exec.arg[1] != NULL
	   && (my_strcmp(data->exec.arg[1], "-") == 0))
    cd_to_back(data);
  else if (data->exec.arg[1] != NULL)
    cd_to_file(data);
}
