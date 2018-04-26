/*
** match.c for  in /home/rozier_s/Desktop/dev/test_42
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Sat May 28 10:18:08 2016 simon ROZIER
** Last update Tue Jun 07 14:48:28 2016 Maxime Aubanel
*/

#include "my.h"

char	*my_customiz(char *str, int k)
{
  int	i;
  char	*res;
  int	j;

  i = -1;
  j = 0;
  if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
    exit(EXIT_FAILURE);
  while (str[++i] != '\0')
    {
      if (i != k)
	{
	  res[j] = str[i];
	  j = j + 1;
	}
    }
  res[j] = '\0';
  free(str);
  return (res);
}
int	my_size(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] == ' ')
    i = i + 1;
  return (5 + i);
}

int	my_find(char *ts, char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == ts[j])
	j = j + 1;
      if (ts[j] == '\0')
	return (0);
    }
  return (1);
}

int	my_match(char *str, char *match, char c)
{
  if (str == (char *)(0) || match == (char *)(0))
    return (-1);
  if (*str == 0 && *match == 0)
    return (1);
  else if (*match == c)
    {
      if (*str == 0)
	return (my_match((str), (match + 1), c));
      else
	return (my_match((str + 1), (match), c) ||
		my_match((str), (match + 1), c));
    }
  else if (*match != *match)
    return (0);
  else
    return (my_match(str + 1, match + 1, c));
}

int	the_nsame(char *str, char *val)
{
  int   i;
  int	nb;

  i = -1;
  if (str == NULL || val == NULL)
    return (1);
  nb = my_strlen(val);
  while (++i < nb && val[i] != '\0' && str[i] != '\0')
    {
      if (str[i] != val[i])
        return (1);
      i = i + 1;
    }
  return (0);
}
