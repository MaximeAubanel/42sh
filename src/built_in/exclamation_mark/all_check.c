/*
** all_check.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/src/built_in/exclamation_mark
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Sat Jun 04 04:21:17 2016 deforges
** Last update Sat Jun 04 04:22:29 2016 deforges
*/

#include "my.h"

int		neg_zero(char *mark)
{
  if (mark[1] == '-' && mark[2] == '0')
    return (1);
  return (0);
}

int		check_one_mark(char *str)
{
  int		i;

  i = -1;
  while (str && str[++i])
    {
      if ('!' == str[i] && (str[i + 1] == ' ' || str[i + 1] == '\0'))
	return (-1);
    }
  return (0);
}

int		check_mark(char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str && str[++i])
    {
      if ('!' == str[i])
	return (1);
    }
  return (0);
}

int		check_if_history(char *str)
{
  char		*mark;
  int		i;
  int		len_cmd;

  i = -1;
  mark = get_exclamation(str);
  while (mark && mark[++i]);
  len_cmd = my_strlen(str);
  if (len_cmd == i)
    return (1);
  return (0);
}

int		check_error(t_data* data, char *mark, int pos)
{
  if (data->cmd->head == NULL)
    return (-1);
  if (neg_zero(mark) == 1)
    return (-2);
  if (pos > data->nb)
    return (-1);
  else if (pos == 0)
    return (-1);
  return (0);
}
