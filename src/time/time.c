/*
** time.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/time
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 02 12:28:43 2016 Maxime Aubanel
** Last update Tue Jun 07 13:18:26 2016 Maxime Aubanel
*/

#include <time.h>
#include "my.h"

void			put_in_history(t_data *data, char *str, char *timer, int x)
{
  (void)timer;
  if (data->cmd->head == NULL)
    first_ini_double(data->cmd, str, x);
  else
    end_list_double(data->cmd, str, x);
  data->my_cmd.cmd = str;
}

void			my_history(t_data *data, char *str)
{
  t_cmd			*current;

  (void)str;
  reset_shell_mode();
  current = data->cmd->head;
  while (current != NULL)
    {
      printf("    %d  %s  %s\n", current->x, current->timer, current->str);
      current = current->next;
    }
  reset_prog_mode();
}

char			*parse_time(char *str)
{
  int			i;
  char			*new;
  int			x;
  int			w;

  w = 0;
  x = 0;
  i = 0;
  new = malloc(sizeof(char) * 6);
  while (str[i + 2] != ':')
    i = i + 1;
  x = i;
  while (x != i + 5)
    {
      new[w] = str[x];
      w = w + 1;
      x = x + 1;
    }
  new[w] = '\0';
  return (new);
}

char			*my_time()
{
  time_t		timer;
  char			*tim;
  char			*new_time;

  timer = time(NULL);
  tim = asctime(localtime(&timer));
  new_time = parse_time(tim);
  return (new_time);
}
