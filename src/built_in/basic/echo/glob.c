/*
** glob.c for  in /home/rozier_s/rendu/C_elem/PSU_2015_42sh
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Tue May 31 16:35:19 2016 simon ROZIER
** Last update Tue Jun 07 14:51:27 2016 Maxime Aubanel
*/

#include <glob.h>
#include "my.h"

int		my_check_glob(char **str)
{
  int		a;
  int		b;
  int		i;

  a = 0;
  b = 0;
  i = -1;
  while (str[0][++i] != '\0')
    {
      if (str[0][i] == '{')
	a += 1;
      else if (str[0][i] == '}')
	b += 1;
    }
  if (a != b || a == 0 || b == 0)
    return (0);
  my_changestr(str, '{', '[');
  my_changestr(str, '}', ']');
  return (1);
}

void		my_add(char **str, char *add, int *k)
{
  if (*k > 0)
    {
      my_strncpyx((*str), " ", *k, 1);
      *k = *k + 1;
    }
  my_strncpyx((*str), add, *k, my_strlen(add));
  *k += my_strlen(add);
}

char		*my_gui(char *res, char *first, char **tab, glob_t gloob)
{
  int		*var;
  int		a;
  int		i;
  int		k;

  k = 0;
  a = -1;
  i = -1;
  if ((var = my_init_var(gloob.gl_pathc)) == NULL)
    return (NULL);
  while (tab[++a] != NULL)
    {
      i = -1;
      while (++i < (int)gloob.gl_pathc)
	{
	  if (var[i] == 0 &&
	      my_2find(first, tab[a], gloob.gl_pathv[i], '*') == 1)
	    {
	      var[i] = 1;
	      my_add(&res, gloob.gl_pathv[i], &k);
	    }
	}
    }
  res[k] = '\0';
  return (res);
}

char		*my_take_str(char *res, char *str, glob_t gloob, int o)
{
  int		i;
  int		k;

  i = -1;
  k = 0;
  if (o == 0)
    {
      while (++i < (int)gloob.gl_pathc)
	my_add(&res, gloob.gl_pathv[i], &k);
      res[k] = '\0';
    }
  else if (o == 1)
    {
      while (str[++i] != '[' && str[i] != '\0');
      o = i;
      while (str[++i] != ']' && str[i] != '\0');
      str[i] = '\0';
      str[o] = '\0';
      res = my_gui(res, str, my_str_to_wordtab(str + o + 1, ',',
					       my_strlen(str + o + 1)), gloob);
    }
  return (res);
}

char		*my_glob(char *str)
{
  glob_t	gloob;
  int		i;
  int		k;
  char		*res;
  int		o;

  i = -1;
  k = 0;
  if ((o = my_check_glob(&str)) == -1 || my_find("\"", str) == 0 ||
      my_find("'", str) == 0 || glob(str, 0, NULL, &gloob) == GLOB_ERR)
    {
      return (NULL);
    }
  if (gloob.gl_pathc == 0)
    return (NULL);
  while (++i < (int)gloob.gl_pathc)
    k += my_strlen(gloob.gl_pathv[i]) + 1;
  if ((res = malloc(sizeof(char) * k + 1)) == NULL)
    return (NULL);
  k = 0;
  res = my_take_str(res, str, gloob, o);
  globfree(&gloob);
  return (res);
}
