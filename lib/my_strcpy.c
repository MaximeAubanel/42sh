/*
** my_strcpy.c for strcpy in /home/aubane_m/rendu/PSU/PSU_2015_tetris/lib
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Feb 23 16:04:23 2016 Maxime Aubanel
** Last update Sat Jun 04 03:01:31 2016 Maxime Aubanel
*/

#include "lib.h"

char			*my_strcpy(char *dest, char *src)
{
  int			i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
