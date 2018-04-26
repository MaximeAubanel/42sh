/*
** bashrc_ncurse.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Jun 03 18:53:57 2016 Maxime Aubanel
** Last update Tue Jun 07 13:17:35 2016 Maxime Aubanel
*/

#include "my.h"

void			parse_alias_bashrc(char *str, t_data *data, int x, int size)
{
  char			**tab;

  tab = str_to_wordtab(str);
  data->bashrc.alias[x].cmd = tab[3];
  data->bashrc.alias[x].alias = tab[1];
  data->bashrc.alias[x].param = tab[4];
  if (x == size - 1)
    {
      data->bashrc.alias[x + 1].cmd = NULL;
      data->bashrc.alias[x + 1].alias = NULL;
      data->bashrc.alias[x + 1].param = NULL;
    }
}

void			init_bashrc(t_data *data)
{
  int			fd;
  char			*str;
  int			x;
  int			size;

  size = 0;
  x = -1;
  if (((fd = open(".bashrc", O_RDONLY, S_IWUSR | S_IRUSR))) < 0)
    {
      data->bashrc_ex = 0;
      return;
    }
  else
    data->bashrc_ex = 1;
  while ((str = get_next_line(fd)) != NULL)
    ++size;
  data->bashrc.alias = malloc(sizeof(t_alias) * (size + 1));
  fd = open(".bashrc", O_RDONLY, S_IWUSR | S_IRUSR);
  while ((str = get_next_line(fd)) != NULL)
    parse_alias_bashrc(str, data, ++x, size);
}
