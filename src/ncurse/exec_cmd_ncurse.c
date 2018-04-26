/*
** exec_cmd_ncurse.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sat Jun 04 10:42:58 2016 Maxime Aubanel
** Last update Tue Jun 07 16:14:38 2016 Maxime Aubanel
*/

#include "my.h"

int			my_init(t_data *data, char *str)
{
  int			x;

  data->exec.cmd_str = normalize_str(str);
  if ((x = check_if_alias(data, data->exec.cmd_str)) != -1)
    data->exec.cmd_str =
      completion(data->exec.cmd_str, data->bashrc.alias[x].cmd,
		 data->bashrc.alias[x].alias);
  if ((data->exec.cmd_nrml = normalize_str(data->exec.cmd_str)) == NULL)
    return (-1);
  data->exec.arg = str_to_wordtab(data->exec.cmd_nrml);
  data->exec.cmd_str = add_a_char(data->exec.arg[0], '/');
  data->exec.path = PATH_to_str(data->exec.env);
  data->exec.path = my_strcat(data->exec.path, ":./");
  data->exec.path_tab = str_to_wordtab(data->exec.path);
  data->exec.path_tab = add_in_tab(data->exec.path_tab, data->exec.cmd_str);
  data->exec.access = check_access(data->exec.path_tab);
  return (0);
}

void			my_set_history(t_data *data)
{
  if (data->mark_alone == false && data->mark == false)
    {
      data->my_cmd.nb = data->my_cmd.nb + 1;
      data->my_cmd.x = data->my_cmd.x + 1;
      data->nb += 1;
      put_in_history(data, data->my_cmd.cmd, my_time(), data->nb);
    }
  else if (data->mark_alone == true && data->mark == true)
    {
      data->my_cmd.nb = data->my_cmd.nb + 1;
      data->my_cmd.x = data->my_cmd.x + 1;
      data->nb += 1;
      put_in_history(data, data->my_cmd.cmd, my_time(), data->nb);
    }
  else
    {
      data->my_cmd.nb = data->my_cmd.nb + 1;
      data->my_cmd.x = data->my_cmd.x + 1;
      data->nb += 1;
      put_in_history(data, data->my_cmd.cmd, my_time(), data->nb);
    }
}

void			my_exclamation_mark(t_data *data)
{
  if (data->cmd->head == NULL && check_mark(data->my_cmd.cmd) == 1)
    data->my_cmd.cmd = first_mark_history(data, data->my_cmd.cmd);
  else if (data->cmd->head != NULL && check_mark(data->my_cmd.cmd) == 1)
    data->my_cmd.cmd = change_cmd(data, data->my_cmd.cmd);
      my_set_history(data);
}

int			my_reset_cmd(t_data *data, my_ncurse *ncurse)
{
  if (data->mark == false)
    {
      data->my_cmd.cmd = NULL;
      data->mark = true;
      data->mark_alone = false;
      my_prompt_ncurse(data, ncurse);
      return (1);
    }
  return (0);
}

void			my_cmd_exec(t_data *data, my_ncurse *ncurse)
{
  t_node		*root;
  char			*val;

  root = NULL;
  data->my_cmd.nb = data->my_cmd.nb + 1;
  data->my_cmd.x = data->my_cmd.nb + 1;
  put_in_history(data, data->my_cmd.cmd, my_time(), data->my_cmd.nb);
  if ((val = my_globing(data->my_cmd.cmd)) != NULL)
    data->my_cmd.cmd = val;
  else
    {
      my_noneglob(data, ncurse, data->my_cmd.cmd);
      return ;
    }
  if (my_reset_cmd(data, ncurse) == 1)
    return ;
  root = build_tree(data->my_cmd.cmd);
  my_backspace();
  exectree(data, root);
  reset_prog_mode();
  my_prompt_ncurse(data, ncurse);
  data->my_cmd.cmd = NULL;
}
