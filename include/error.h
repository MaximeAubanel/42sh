/*
** error.h for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/include
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Apr 27 20:39:05 2016 Maxime Aubanel
** Last update Thu Jun 02 18:04:35 2016 Maxime Aubanel
*/

#ifndef ERROR_H_
#define ERROR_H_

#include "my.h"

int display_error(t_data *data, int err);

typedef struct s_error {
  int err;
  int returnValue;
  char *msg;
} t_error;


typedef enum error_type {
  NO_PARAM,
  EXIT,
} error_type;

#endif
