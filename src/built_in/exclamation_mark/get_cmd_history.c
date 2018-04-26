/*
** get_cmd_history.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/src/built_in/exclamation_mark
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Sat Jun 04 04:19:23 2016 deforges
** Last update Tue Jun 07 13:10:50 2016 Maxime Aubanel
*/

#include "my.h"

char		*get_exclamation(char *cmd)
{
  char		*get_pos;
  int		i;
  int		e;

  i = -1;
  e = -1;
  if ((get_pos = malloc(sizeof(char) * (my_strlen(cmd) + 1))) == NULL)
    return (NULL);
  bzero(get_pos, my_strlen(cmd) + 1);
  while (cmd && cmd[++i])
    {
      if (cmd && cmd[i] == '!')
	{
	  while (cmd && cmd[i] != '\0' && cmd[i] != ' ')
	    {
	      get_pos[++e] = cmd[i];
	      i += 1;
	    }
	  return (get_pos);
	}
    }
  return (NULL);
}

char		*get_cmd_positiv(t_data *data, int pos)
{
  t_cmd		*cmd;
  int		e;

  e = 0;
  cmd = data->cmd->head;
  while (cmd->next != NULL)
    cmd = cmd->next;
  data->last_pos = cmd->x;
  if (pos > 0 && pos <= cmd->x)
    {
      cmd = data->cmd->head;
      while (++e < pos)
	cmd = cmd->next;
    }
  else
    return (NULL);
  return (cmd->str);
}

char		*get_cmd_neg(t_data *data, int pos)
{
  t_cmd		*cmd;
  int 		size;

  size = data->nb;
  cmd = data->cmd->head;
  if (pos > size)
    return (NULL);
  size -= pos;
  cmd = data->cmd->head;
  while (size >= 0 && cmd != NULL)
    {
      if (size == 0)
	return (cmd->str);
      cmd = cmd->next;
      --size;
    }
  return (cmd->str);
}

char		*get_cmd(t_data *data, char *mark, int pos)
{
  char		*cmd;
  int		i;

  i = -1;
  while (mark && mark[++i])
    {
      if (mark[i] == '!' && mark[i + 1] == '-')
	cmd = get_cmd_neg(data, pos);
      else if (mark[i] == '!')
	cmd = get_cmd_positiv(data, pos);
    }
  return (cmd);
}

void		my_print_cmd(t_data *data, char *cmd)
{
  if (cmd != NULL)
    {
      if ((check_one_mark(cmd) == 0) &&
	  data->isnum == true && data->mark == true)
	{
	  reset_shell_mode();
	  my_putchar('\n');
	  my_putstr(cmd);
	  reset_prog_mode();
	}
    }
}
