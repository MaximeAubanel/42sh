/*
** my_bzero.c for PSU_2015_tetris in /home/deforg_a/rendu/PSU/PSU_2015_tetris/lib
**
** Made by antoine deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Mon Mar 07 16:36:55 2016 antoine deforges
** Last update Tue Apr 26 15:15:27 2016 Maxime Aubanel
*/

#include "lib.h"

void			my_bzero(char *str, int size)
{
  int			y;

  y = 0;
  while (y < size)
    {
      str[y] = 0;
      y = y + 1;
    }
}
