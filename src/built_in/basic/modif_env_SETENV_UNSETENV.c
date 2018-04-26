/*
** modif_env.SETENV_UNSETENV.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 18:25:17 2016 Maxime Aubanel
** Last update Sun Jun 05 07:03:03 2016 deforges
*/

 #include "my.h"

 void			new_env_null(t_data *data)
 {
   char			*new;

   if ((new =
	malloc(sizeof(char) * (my_strlen(data->exec.arg[1]) + 1))) == NULL)
    return ;
   my_strcpy(new, data->exec.arg[1]);
   my_strcat(new, "=");
   my_strcat(new, "\0");
   end_list(&data->my_list, new);
 }

 void			new_env(t_data *data)
 {
   char			*new;

   if ((new = malloc(sizeof(char) * (my_strlen(data->exec.arg[1])
                       + my_strlen(data->exec.arg[2]) + 1))) == NULL)
    return ;
   my_strcpy(new, data->exec.arg[1]);
   my_strcat(new, "=");
   my_strcat(new, data->exec.arg[2]);
   new[my_strlen(data->exec.arg[1])
   + my_strlen(data->exec.arg[2]) + 1] = '\0';
   end_list(&data->my_list, new);
 }
