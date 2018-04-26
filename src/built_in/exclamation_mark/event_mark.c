/*
** event_mark.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/src/built_in
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Tue May 31 12:07:19 2016 deforges
** Last update Sun Jun 05 07:15:53 2016 deforges
*/

#include "my.h"

char		*event_not_found(t_data *data, char *cmd, char *mark, int pos)
{
  cmd = delet_mark(cmd, mark);
  data->mark = false;
  reset_shell_mode();
  my_putchar('\n');
  if (neg_zero(mark) == 1)
    my_put_nbr(data->nb + 1);
  else
    {
      if (mark[1] == '-')
	my_putchar('-');
      my_put_nbr(pos);
    }
  my_putstr(": Event not found.");
  reset_prog_mode();
  return (cmd);
}

void		build_cmd(t_data *data, char *cmd)
{
  if (check_if_history(cmd) == 1)
    data->mark_alone = true;
}

char		*change_cmd(t_data *data, char *cmd)
{
  char		*mark;
  int		i;

  i = -1;
  while (cmd && cmd[++i])
    {
      if (cmd[i] == '!' && cmd[i + 1] != ' ' && cmd[i + 1] != '\0')
	{
	  mark = get_exclamation(cmd);
	  if (my_isnum(mark) == 0)
	    {
	      build_cmd(data, cmd);
	      cmd = my_change(data, cmd, mark);
	    }
	  else
	    data->isnum = false;
	}
    }
  my_print_cmd(data, cmd);
  return (cmd);
}

char		*delet_mark(char *str, char *mark)
{
  char		**str_cmd;
  char		*cmd;
  int		e;
  int		y;
  int		x;

  e = -1;
  y = -1;
  x = -1;
  str_cmd = str_to_wordtab(str);
  if ((cmd = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  bzero(cmd, my_strlen(str));
  while (str_cmd && str_cmd[++y])
    {
      x = -1;
      if (my_strcmp(str_cmd[y], mark) == 0)
	y++;
      while (str_cmd[y] && str_cmd[y][++x] != '\0')
	cmd[++e] = str_cmd[y][x];
      cmd[++e] = ' ';
    }
  cmd = normalize_str(cmd);
  return (cmd);
}

char		*first_mark_history(t_data *data, char *str)
{
  char		*cmd;
  char		*mark;
  int		pos;
  int		i;

  i = -1;
  pos = 0;
  while (str && str[++i])
    {
      if (str[i] == '!' && str[i + 1] != '\n' && str[i + 1] != '\0')
	{
	  if (check_if_history(str) == 1)
	    data->mark_alone = true;
	  mark = get_exclamation(str);
	  pos = get_pos(mark);
          cmd = delet_mark(str, mark);
          data->mark = false;
	  reset_shell_mode();
	  my_putchar('\n');
	  my_put_nbr(pos);
          my_putstr(": Event not found.");
	  reset_prog_mode();
	}
    }
  return (cmd);
}
