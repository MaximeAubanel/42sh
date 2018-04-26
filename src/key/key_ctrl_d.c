/*
** key_ctrl_d.c for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 30 14:28:13 2016 Maxime Aubanel
** Last update Fri Jun 03 18:14:29 2016 Maxime Aubanel
*/

#include "my.h"

void			key_ctrl_d(t_data *data)
{
  (void)data;
  reset_shell_mode();
  printf("exit\n");
  exit (1);
}
