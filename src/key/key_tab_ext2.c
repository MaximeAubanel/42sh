/*
** key_tab_ext2.c for key_tab in /home/truchl_b/rendu/PSU/PSU_2015_42sh
** 
** Made by Bartosz Truchlewski
** Login   <truchl_b@epitech.net>
** 
** Started on  Sat Jun  4 14:28:02 2016 Bartosz Truchlewski
** Last update Sat Jun  4 15:38:20 2016 Bartosz Truchlewski
*/

#include "my.h"
#include "glob.h"

char	*add_end_star(char *str)
{
  char	*new;
  int	i;

  i = 0;
  new = malloc(sizeof(char) * (my_strlen(str) + 2));
  while (str[i])
    {
      new[i] = str[i];
      i = i + 1;
    }
  new[i] = '*';
  new[i + 1] = '\0';
  return (new);
}

int	display_glob(char **glob, t_data *data, char *word)
{
  int	i;

  (void)data;
  i = 0;
  if (my_strcmp(word, glob[0]) == 0)
    return (-1);
  while (glob[i])
    {
      my_putstr(glob[i]);
      my_putchar('\t');
      i = i + 1;
    }
  my_putstr(glob[i]);
  my_putchar('\n');
  return (0);
}

char	*my_revstr(char *str)
{
  int	i;
  int	len;
  char	c;

  len = my_strlen(str);
  i = 0;
  while (i < len / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + len - i - 1);
      *(str + len - i - 1) = c;
      ++i;
    }
  return (str);
}

char	*return_word(t_data *data)
{
  int	x;
  int	y;
  char	*new;
  int	size;
  char	cmd[100];
  int	i;

  i = 0;
  getyx(data->ncurse.win, y, x);
  size = x - 4;
  data->ncurse.posx = size;
  data->ncurse.posy = y;
  while (data->my_cmd.cmd[size] != ' ' && data->my_cmd.cmd[size] != '\0')
    {
      cmd[i] = data->my_cmd.cmd[size];
      i = i + 1;
      size = size - 1;
    }
  cmd[i] = '\0';
  new = add_end_star(my_revstr(cmd));
  return (new);
}
