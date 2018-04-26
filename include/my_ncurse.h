/*
** my_ncurse.h for le42 in /home/aubane_m/rendu/PSU/le42/include
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue May 03 14:02:58 2016 Maxime Aubanel
** Last update Thu Jun 02 18:03:35 2016 Maxime Aubanel
*/

#include <ncurses.h>

/*######################################*/
/*###############           ###########*/
/*##############  NCURSES  ###########*/
/*#############           ###########*/
/*##################################*/

typedef struct		my_ncurse
{
  WINDOW		*win;
  int			posx;
  int			posy;
}			my_ncurse;
