/*
** my_getnbr.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Apr 27 12:18:17 2016 Maxime Aubanel
** Last update Wed Apr 27 12:21:17 2016 Maxime Aubanel
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	sgn;
  int	rez;

  sgn = 1;
  rez = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sgn = - sgn;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (rez > 214748364)
	return (0);
      if (rez == 214748364 && *str > 7 && sgn == 1)
	return (0);
      if (rez == 214748364 && *str > 8 && sgn == -1)
	return (0);
      rez = rez * 10 + *str - 48;
      str = str + 1;
    }
  if (sgn == -1)
    rez = - rez;
  return (rez);
}

void	my_put_nbr(int nbr)
{
  int	mod;
  int	div;

  if (nbr < 0 && nbr > -10)
    my_putchar('-');
  mod = nbr % 10;
  div = nbr / 10;
  if (nbr >= 10 || nbr <= -10)
    my_put_nbr(div);
  if (mod < 0)
    mod = - mod;
  my_putchar(mod + '0');
}
