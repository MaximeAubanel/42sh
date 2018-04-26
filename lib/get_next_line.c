/*
** get_next_line.c for get_next_line.c in /home/ferlet_n/getnextline
**
** Made by nicolas ferlet
** Login   <ferlet_n@epitech.net>
**
** Started on  Mon Jan  4 09:33:52 2016 nicolas ferlet
** Last update Tue Jun 07 13:22:58 2016 Maxime Aubanel
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int	check(char *str, int choice)
{
  int	i;

  i = 0;
  if (choice == 0)
    {
      while (str[i] != '\0')
	{
	  if (str[i] == '\n')
	    return (1);
	  i = i + 1;
	}
      return (0);
    }
  else
    {
      while (str[i] != '\0')
	i = i + 1;
      return (i);
    }
  return (0);
}

char	*my_strcpy2(char *all_read, char *read_init, int a)
{
  char	*tmp;
  int	i;
  int	j;

  if ((tmp = malloc((check(all_read, 1) + 1 + a) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (all_read[i] != '\0')
    {
      tmp[i] = all_read[i];
      i = i + 1;
    }
  while (j != a)
    {
      tmp[i + j] = read_init[j];
      j = j + 1;
    }
  tmp[i + j] = '\0';
  free(all_read);
  return (tmp);
}

void	copy_stock(char *all_read, int i, int j, char *stock)
{
  while (i != READ_SIZE)
    {
      stock[i] = '\0';
      i = i + 1;
    }
  i = 0;
  while (all_read[j] != '\0' && all_read[j] != '\n')
    j = j + 1;
  if (all_read[j] == '\n')
    {
      all_read[j] = '\0';
      j = j + 1;
      while (all_read[j] != '\0')
	{
	  stock[i] = all_read[j];
	  all_read[j] = '\0';
	  i = i + 1;
	  j = j + 1;
	}
    }
}

char	*alter(t_struct s, char *read_init, char *all_read, char *stock)
{
  while (check(read_init, 0) == 0 && check(all_read, 0) == 0 && s.a != 0)
    {
      if ((s.a = read(s.fd, read_init, READ_SIZE)) == -1)
	{
	  free(read_init);
	  free(all_read);
	  return (NULL);
	}
      read_init[s.a] = '\0';
      if ((all_read = my_strcpy2(all_read, read_init, s.a)) == NULL)
        {
          free(read_init);
          return (NULL);
        }
    }
  free(read_init);
  if (all_read[0] == '\0')
    {
      free(all_read);
      return (NULL);
    }
  copy_stock(all_read, 0, 0, stock);
  return (all_read);
}

char		*get_next_line(const int fd)
{
  char		*read_init;
  char		*all_read;
  t_struct	s;
  static char	stock[READ_SIZE];

  if ((read_init = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  read_init[0] = '\0';
  s.a = 1;
  s.fd = fd;
  if ((all_read = malloc(READ_SIZE * sizeof(char))) == NULL)
    {
      free(read_init);
      return (NULL);
    }
  all_read[0] = '\0';
  if ((all_read = my_strcpy2(all_read, stock, READ_SIZE)) == NULL)
    {
      free(read_init);
      return (NULL);
    }
  return (alter(s, read_init, all_read, stock));
}
