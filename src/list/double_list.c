/*
** double_list.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/list
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Apr 27 13:26:27 2016 Maxime Aubanel
** Last update Sun Jun  5 22:03:43 2016 ferlet
*/

#include "my.h"

void			init_list_double(t_list_cmd **list)
{
  (*list) = malloc(sizeof(t_list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
  (*list)->size = 0;
}

void			first_ini_double(t_list_cmd *list, char *str, int x)
{
  t_cmd		*new;

  new = malloc(sizeof(t_cmd));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = my_strcpy(new->str, str);
  new->next = NULL;
  new->prev = NULL;
  new->x = x;
  new->timer = my_time();
  list->head = new;
  list->tail = new;
  list->size = list->size + 1;
}

void			top_list_double(t_list_cmd *list, char *str, int x)
{
  t_cmd		*new;
  (void)x;

  new = malloc(sizeof(t_cmd));
  new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
  new->str = str;
  new->prev = NULL;
  new->next = list->head;
  list->head = new;
  list->size = list->size + 1;
}

void			end_list_double(t_list_cmd *list, char *str, int x)
{
  t_cmd		*new;

  if (str != NULL)
    {
      new = malloc(sizeof(t_cmd));
      new->str = malloc(sizeof(char) * (my_strlen(str) + 1));
      new->str = my_strcpy(new->str, str);
      new->next = NULL;
      new->x = x;
      new->timer = my_time();
      list->tail->next = new;
      list->tail = new;
      list->size = list->size + 1;
    }
}

void			display_list_double(t_list_cmd *list)
{
  t_cmd			*current;

  current = list->head;
  while (current != NULL)
    {
      printf("%d    %s   %s\n", current->x, current->timer, current->str);
      current = current->next;
    }
}
