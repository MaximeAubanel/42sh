/*
** list.c for PSU_2015_minishell2 in /home/aubane_m/rendu/PSU/PSU_2015_minishell2/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Mar 29 10:54:17 2016 Maxime Aubanel
** Last update Sat Jun 04 01:27:34 2016 Maxime Aubanel
*/

#include "my.h"

void			init_list(t_list **list)
{
  *list = malloc(sizeof(t_list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
  (*list)->size = 0;
}

void			first_ini(t_list *list, char *str)
{
  t_elem		*new;

  new = malloc(sizeof(t_elem));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = str;
  new->next = NULL;
  list->head = new;
  list->tail = new;
  list->size = list->size + 1;
}

void			top_list(t_list *list, char *str)
{
  t_elem		*new;

  new = malloc(sizeof(t_elem));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = str;
  new->next = list->head;
  list->head = new;
  list->size = list->size + 1;
}

void			end_list(t_list *list, char *str)
{
  t_elem		*new;

  new = malloc(sizeof(t_elem));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = str;
  list->tail->next = new;
  new->next = NULL;
  list->tail = new;
  list->size = list->size + 1;
}

void			delete_list(t_list *list, int pos)
{
  t_elem		*current;
  t_elem		*supp_elem;
  int			i;

  i = 0;
  current = list->head;
  if (pos == 0)
    {
      list->head = list->head->next;
      list->size = list->size - 1;
      return ;
    }
  while (i != pos - 1)
    {
      current = current->next;
      i = i + 1;
    }
  supp_elem = current->next;
  current->next = current->next->next;
  if (current->next == NULL)
    list->tail = current;
  list->size = list->size - 1;
  free (supp_elem);
}
