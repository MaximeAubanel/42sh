/*
** lib.h for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/include
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Tue Apr 26 15:14:18 2016 Maxime Aubanel
** Last update Sun Jun  5 22:38:43 2016 ferlet
*/

#include <unistd.h>
#include "stdlib.h"

/*######################################*/
/*###############           ###########*/
/*##############    LIB    ############*/
/*#############           ############*/
/*###################################*/

typedef struct	s_struct
{
  int		a;
  int		fd;
}		t_struct;

char		*get_next_line(const int fd);
char		*add_to_line(char *line, int treat, char *buff, int *start);
int     	my_strncmp(char *cmp1, char *cmp2, int nb);
int     	my_strcmp(char *cmp1, char *cmp2);
char		*my_strcpy(char *dest, char *src);
void		my_putstr(char *str);
int		my_getnbr(char *str);
void		my_putchar(char c);
int		my_strlen(char *str);
char    	*my_strcat(char *dest, char *src);
void		my_put_nbr(int nb);
char		*get_next_line(const int fd);
char		**str_to_wordtab(char *str);
void		my_bzero(char *str, int size);
void		my_putstr(char *str);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_revstrncpy(char *str, int i);
char		*my_revstr(char *str);
int		my_isnum(char *str);

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char		*get_next_line(const int fd);
char		*add_to_line(char *line, int treat, char *buff, int *start);

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
