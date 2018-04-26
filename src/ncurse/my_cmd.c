/*
** my_cmd.c for le42 in /home/aubane_m/rendu/PSU/le42/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 23 14:00:43 2016 Maxime Aubanel
** Last update Tue Jun 07 13:43:32 2016 Maxime Aubanel
*/

#include "my.h"

char			*add_ch_in_line(my_ncurse *ncurse, int ch, char *str)
{
  char			*new;
  int			x;
  int			y;

  getyx(ncurse->win, y, x);
  new = malloc(sizeof(char) * ((my_strlen(str) + 3)));
  y = 0;
  while (y != x - 3)
    {
      new[y] = str[y];
      y = y + 1;
    }
  new[y] = ch;
  while (str[y])
    {
      y = y + 1;
      new[y] = str[y -1];
    }
  new[y + 1] = str[y];
  new[y + 2] = '\0';
  return (new);
}

char			*add_line(char *str, char ch, my_ncurse *ncurse)
{
  char			*new;
  int			y;
  int			x;

  getyx(ncurse->win, y, x);
  (void)y;
  if (str == NULL)
    {
      new = malloc(sizeof(char) * 2);
      new[0] = ch;
      new[1] = '\0';
    }
  if (str != NULL && x == (my_strlen(str) + 4))
    {
      new = malloc(sizeof(char) * (my_strlen(str) + 2));
      new = my_strcpy(new, str);
      new[my_strlen(str)] = ch;
      new[my_strlen(str) + 1] = '\0';
    }
  else if (str != NULL && x != (my_strlen(str) + 4))
    new = add_ch_in_line(ncurse, ch, str);
  return (new);
}
