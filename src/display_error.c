/*
** displayError.c for in /home/aubane_m/rendu/PSU/PSU_2015_42sh/src
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Apr 27 21:15:18 2016 Maxime Aubanel
** Last update Sat Jun  4 14:14:05 2016 Bartosz Truchlewski
*/

#include <stdlib.h>
#include <stdio.h>
#include "error.h"

t_error g_error_msg[] = {
  {NO_PARAM, -1, "No parameter needed."},
  {EXIT, -1, "exit"},
  {0, 0, NULL},
};

int	display_error(t_data *data, int err)
{
  int	i;

  i = 0;
  while (g_error_msg[i].msg)
    {
      if (g_error_msg[i].err == err)
	{
	  kill(data->pid_f, SIGUSR1);
	  printf("%s\n", g_error_msg[i].msg);
	  return (g_error_msg[i].returnValue);
	}
      i = i + 1;
  }
  return (EXIT_SUCCESS);
}
