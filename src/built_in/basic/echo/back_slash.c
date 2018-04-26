/*
** back_slash.c for  in /home/rozier_s/rendu/C_elem/PSU_2015_42sh
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Sun May 29 17:03:06 2016 simon ROZIER
** Last update Tue Jun 07 14:30:46 2016 Maxime Aubanel
*/

#include "my.h"

void	exec_back(char c)
{
  if (c == 'a')
    my_putchar('\a');
  if (c == 'b')
    my_putchar('\b');
  if (c == 't')
    my_putchar('\t');
  if (c == 'n')
    my_putchar('\n');
  if (c == 'f')
    my_putchar('\f');
  if (c == 'r')
    my_putchar('\r');
  if (c == 'e')
    my_putchar('\e');
  if (c == 'v')
    my_putchar('\v');
}

int	my_slash(int *k)
{
  int	i;

  i = 0;
  if (*k < 1)
    return (0);
  while (*k >= 0)
    {
      if (i == 4)
	i = 0;
      if (i == 2)
	my_putchar('\\');
      *k = *k - 1;
      i = i + 1;
    }
  return (i);
}

int	my_slash_slash(int *k)
{
  int	i;

  i = 0;
  if (*k < 1)
    return (0);
  while (*k >= 0)
    {
      if (i == 4)
	{
	  i = 0;
	  my_putchar('\\');
	}
      *k = *k - 1;
      i = i + 1;
    }
  return (i);
}

int	my_print_slash(char *str)
{
  int	i;
  int	k;
  int	a;
  char	b[] = "abefnrtv";

  i = -1;
  k = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '\\')
	k = k + 1;
      else if (i > 1 && str[i] != '\\' && str[i - 1] == '\\' &&
	       str[i - 2] == '\\' && my_slash_slash(&k) > 2)
	{
	  a = -1;
	  while (++a < 9 && str[i] != b[a]);
	  if (a > 8)
	    my_putchar(str[i]);
	  else
	    exec_back(b[a]);
	}
      else
	my_putchar(str[i]);
    }
  return (k);
}

void	my_backslash(t_data *data, t_d *val)
{
  (void)data;
  int	k;
  char	*get;
  int	i;

  k = 1;
  i = my_strlen(val->tab[val->i]) - 1;
  get = NULL;
  if (val->tab[val->i][i] == '\\')
    {
      while (val->tab[val->i][--i] == '\\' && ++k < 1000);
      if (k > 0 && k % 2 == 1)
	{
	  my_putstr("? ");
	  get = get_next_line(0);
	}
    }
  k = my_print_slash(val->tab[val->i]);
  i = my_strlen(val->tab[val->i]) - 1;
  if (val->tab[val->i][i] == '\\')
    my_slash(&k);
  if (get != NULL)
    my_2print(get, ' ');
}
