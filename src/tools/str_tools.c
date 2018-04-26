/*
** str_tools.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 17:01:24 2016 Maxime Aubanel
** Last update Tue Jun 07 16:41:48 2016 Maxime Aubanel
*/

#include "my.h"

char			*normalize_str(char *str)
{
  char			*new_str;
  int			x1;
  int			x2;

  if (str == NULL)
    return (NULL);
  if (my_strcmp(str, "\n") == 0)
    return ("\n");
  x1 = 0;
  x2 = 0;
  new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[x1] != '\0')
    {
      if (str[x1] != '\t' && str[x1] != ' ')
	new_str[x2++] = str[x1];
      else if (str[x1] == ' ' && str[x1 + 1] != ' ' && x2 != 0)
	new_str[x2++] = str[x1];
      else if (str[x1] == '\t' && str[x1 + 1] != ' ' && x2 != 0)
	new_str[x2++] = ' ';
      x1 = x1 + 1;
    }
  new_str[x2] = '\0';
  if (new_str[my_strlen(new_str) - 1] == ' ')
    new_str[my_strlen(new_str) - 1] = '\0';
  return (new_str);
}

char			*add_a_char(char *str, char c)
{
  int			nbr_char;
  char			*dest;
  int			i;

  i = 1;
  nbr_char = my_strlen(str) + 1;
  dest = malloc((nbr_char + 1) * sizeof(char));
  dest[0] = c;
  while (str[i - 1] != 0)
    {
      dest[i] = str[i - 1];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
