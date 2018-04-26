/*
** list_tools.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu Apr 14 18:29:46 2016 Maxime Aubanel
** Last update Wed Apr 27 13:21:00 2016 Maxime Aubanel
*/

#include "my.h"

char			**list_in_chartab(t_list *list)
{
  char			**tab;
  t_elem		*current;
  int			y;

  y = 0;
  current = list->head;
  tab = malloc(sizeof(char*) * (list->size + 1));
  while (current->next != NULL)
    {
      tab[y] = malloc(sizeof(char) *(my_strlen(current->str) + 2));
      tab[y] = my_strcpy(tab[y], current->str);
      tab[y][my_strlen(current->str)] = '\0';
      current = current->next;
      y = y + 1;
    }
  tab[y] = NULL;
  return (tab);
}

void			change_list(t_list *list, char *str, int pos)
{
  t_elem		*current;
  t_elem		*new;
  int			i;

  i = 0;
  current = list->head;
  while (i != (pos) && current != NULL)
    {
      current = current->next;
      i = i + 1;
    }
  new = malloc(sizeof(t_elem));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = str;
  new->next = current->next->next;
  current->next = new;
  if (current->next == NULL)
    list->tail = current;
}

void			display_list(t_list *list)
{
  t_elem		*current;

  current = list->head;
  while (current->next != NULL)
    {
      my_putstr(current->str);
      my_putchar('\n');
      current = current->next;
    }
  my_putstr(current->str);
  my_putchar('\n');
}

t_list			*tab_in_list(t_list *list, char **env)
{
  int			x;

  x = 1;
  init_list(&list);
  first_ini(list, env[0]);
  list->size = 0;
  while (env[x] != NULL)
    {
      end_list(list, env[x]);
      list->size = list->size + 1;
      x = x + 1;
    }
  return (list);
}
