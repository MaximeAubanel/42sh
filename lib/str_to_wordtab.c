/*
** str_to_wordtab.c for PSU_2015_tetris in /home/aubane_m/rendu/PSU/PSU_2015_tetris
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Fri Feb 26 17:00:40 2016 Maxime Aubanel
** Last update Tue Jun 07 13:22:34 2016 Maxime Aubanel
*/

#include "lib.h"

void			display_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int			count_word(char *str)
{
  int		i;
  int		x;

  x = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':' || str[i] == ' ' || str[i] == '\n')
	x = x + 1;
      i = i + 1;
    }
  return (x);
}

int			return_backslash(char *str, int x)
{
  while (str[x] != '\0' && str[x] != '\n' &&
	 str[x] != ' ' && str[x] != ':')
    {
      x = x + 1;
    }
  return (x);
}

void			init_wordtab(int *y, int *i, int *x)
{
  (*x) = 0;
  (*y) = 0;
  (*i) = 0;
}

char			**str_to_wordtab(char *str)
{
  char		**tab;
  int		nb_word;
  int		y;
  int		i;
  int		nb;
  int		x;

  x = 0;
  y = 0;
  i = 0;
  nb_word = count_word(str);
  tab = malloc(sizeof(char*) * (nb_word + 1));
  while (nb_word-- != 0)
    {
      x = 0;
      nb = return_backslash(str, i);
      tab[y] = malloc(sizeof(char) * (nb + 1));
      while (i != nb)
	tab[y][x++] = str[i++];
      tab[y++][x] = '\0';
      i = nb + 1;
    }
  tab[y] = NULL;
  return (tab);
}
