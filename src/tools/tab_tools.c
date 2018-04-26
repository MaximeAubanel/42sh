/*
** tab_tools.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Sun Mar 27 18:34:37 2016 Maxime Aubanel
** Last update Mon May 02 17:01:05 2016 Maxime Aubanel
*/

#include "my.h"

char			**add_in_tab(char **tab, char *str)
{
  int			i;
  int			x;
  char			*str2;

  i = 0;
  while (tab[i] != NULL)
    {
      str2 = tab[i];
      x = my_strlen(tab[i]);
      tab[i] = malloc((sizeof(char) * x)
		      + (sizeof(char) * my_strlen(str) + 1));
      tab[i][x + my_strlen(str)] = '\0';
      tab[i] = my_strcpy(tab[i], str2);
      tab[i] = my_strcat(tab[i], str);
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}
