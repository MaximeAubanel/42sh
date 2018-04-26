/*
** key_parser.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 23 14:06:55 2016 Maxime Aubanel
** Last update Sat Jun  4 14:22:58 2016 Bartosz Truchlewski
*/

#include "my.h"

t_key			tab_key[] = {
  {KEY_DOWN, &key_down},
  {KEY_LEFT, &key_left},
  {KEY_UP, &key_up},
  {KEY_RIGHT, &key_right},
  {KEY_BACKSPACE, &key_delete},
  {1, &key_ctrl_a},
  {4, &key_ctrl_d},
  {11, &key_ctrl_k},
  {25, &key_ctrl_y},
  {5, &key_ctrl_e},
  {12, &key_ctrl_l},
  {9, &key_tab},
  {0, NULL}
};

int			check_ch(t_data *data, int ch)
{
  int			i;

  i = -1;
  while (tab_key[++i].fct != NULL)
    {
      if (ch == tab_key[i].key)
	{
	  tab_key[i].fct(data);
	  return (0);
	}
    }
  return (-1);
}
