/*
** help.c for  in /home/rozier_s/Desktop/dev/minishell
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Tue Mar 29 15:31:52 2016 simon ROZIER
** Last update Tue Jun 07 14:47:38 2016 Maxime Aubanel
*/

#include "my.h"

int	the_same(char *str, char *val)
{
  int	i;

  i = 0;
  if (c_str_len(str, 'a', 2) != c_str_len(val, 'a', 2))
    return (0);
  while (val[i] != '\0' && str[i] != '\0')
    {
      if (str[i] != val[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

int	my_2find(char *first, char *end, char *match, char c)
{
  char	*hm;
  int	a;

  if ((hm = malloc(sizeof(char) * my_strlen(first) + my_strlen(end) + 1)) ==
      NULL)
    return (-1);
  my_strncpyx(hm, first, 0, my_strlen(first));
  my_strncpyx(hm, end, my_strlen(first), my_strlen(end));
  hm[my_strlen(first) + my_strlen(end)] = '\0';
  a = my_match(match, hm, c);
  free(hm);
  if (a == -1 || a == 0)
    return (0);
  else
    return (1);
}

void    my_strcpyn(char *str, char *val, int nb, int size)
{
  int   j;

  j = -1;
  while (++j < size)
    {
      str[j] = val[nb];
      ++nb;
    }
}

int     c_str_len(char *str, char c, int k)
{
  int   i;
  int   j;

  i = -1;
  j = 1;
  if (str == NULL)
    return (-1);
  while (str[++i] != '\0')
    {
      if (str[i] == c)
        j = j + 1;
      if (str[i] == c && k == -1)
        return (i);
    }
  if (k == 1)
    return (j);
  i = i - 1;
  return (i);
}

char    **my_str_to_wordtab(char *str, char c, int len)
{
  char  **tab;
  int   a[3];

  a[0] = -1;
  a[1] = -1;
  if ((tab = malloc(sizeof(char*) * (c_str_len(str, '\n', 1) + 1))) == NULL)
    return (NULL);
  while (++a[0] < len)
    {
      if (str[a[0]] == c || a[0] == 0)
        {
	  if (a[0] != 0)
	    tab[a[1]][a[2]] = '\0';
          if ((tab[++a[1]] = malloc(sizeof(char) * len)) == NULL)
            return (NULL);
          a[2] = 0;
        }
      if (str[a[0]] != c)
	tab[a[1]][++a[2] - 1] = str[a[0]];
    }
  tab[a[1]][a[2]] = '\0';
  tab[++a[1]] = NULL;
  return (tab);
}
