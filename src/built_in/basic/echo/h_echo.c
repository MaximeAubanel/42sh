/*
** h_echo.c for  in /home/rozier_s/rendu/C_elem/PSU_2015_42sh
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Fri May 27 15:42:30 2016 simon ROZIER
** Last update Sun Jun 05 00:56:09 2016 Maxime Aubanel
*/

#include "my.h"

void		my_line(t_data *data, t_d *val)
{
  if (data == NULL)
    exit(0);
  if (val->opt != 0 || val->tab[val->i][0] != '-')
    {
      write(1, val->tab[val->i], my_strlen(val->tab[val->i]));
      return ;
    }
  if (val->tab[val->i + 1] != NULL && my_size(val->tab[val->i + 1]) != 0)
    {
      while (val->tab[val->i + 1][0] == ' ')
	val->tab[val->i + 1][0] += 1;
    }
  val->saut = 1;
  val->opt -= 1;
}

void		my_fenv(t_data *data, t_d *val)
{
  t_elem	*tmp;

  tmp = data->my_list.head;
  while (tmp != NULL &&
	 (the_nsame(tmp->str, val->tab[val->i] + 1) != 0 ||
	  tmp->str[my_strlen(val->tab[val->i] + 1)] != '=' ))
    tmp = tmp->next;
  if (tmp == NULL)
    {
      printf("%s: Undefined variable.\n", val->tab[val->i] + 1);
      val->saut = 1;
      return ;
    }
  my_putstr(tmp->str + my_strlen(val->tab[val->i]));
}

void		echo_list(t_list *list)
{
  t_elem	*current;

  current = list->head;
  while (current->next != NULL)
    {
      my_putstr(current->str);
      my_putchar(' ');
      current = current->next;
    }
  my_putstr(current->str);
}

char		*my_crochstar(char *str)
{
  int		i;
  int		k;
  int		l;

  i = -1;
  k = 0;
  l = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '[')
	k += 1;
      if (str[i] == ']')
	l += 1;
    }
  if (k != l || k == 0)
    return (str);
  i = -1;
  while (str[++i] != '\0')
    {
      if (i > 0 && str[i] == '.' && str[i - 1] == '[')
	str = my_customiz(str, i);
    }
  str = custom_epur(str, '[', k);
  str = custom_epur(str, ']', l);
  return (str);
}

void		my_star(t_data *data, t_d *val)
{
  (void)data;
  val->tab[val->i] = my_glob(val->tab[val->i]);
  my_putstr(val->tab[val->i]);
}
