/*
** nrm.c for  in /home/rozier_s/rendu/C_elem/PSU_2015_42sh
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Sun Jun  5 01:14:12 2016 simon ROZIER
** Last update Tue Jun 07 15:06:18 2016 Maxime Aubanel
*/

#include "my.h"

void my_2print(char *str, char c)
{
  my_putchar(c);
  my_putstr(str);
}
void    my_changestr(char **str, char c, char k)
{
  int   i;

  i = -1;
  while (str[0][++i] != '\0')
    {
      if (str[0][i] == c)
        str[0][i] = k;
    }
}

void    my_strncpyx(char *str, char *val, int nb, int size)
{
  int   j;

  j = -1;
  while (++j < size)
    {
      str[nb] = val[j];
      ++nb;
    }
}

char	*my_globing(char *str)
{
  int	i;
  char	*res;
  char	*gl;

  if (my_find("*", str) != 0)
    return (str);
  i = c_str_len(str, '*', -1);
  while (i >= 0 && str[i] != ' ')
    i = i - 1;
  i = i + 1;
  if ((gl = my_glob(str + i)) == NULL)
    return (NULL);
  str[i] = '\0';
  if ((res = malloc(sizeof(char) * my_strlen(gl) + my_strlen(str))) == NULL)
    return (NULL);
  my_strncpyx(res, str, 0, my_strlen(str));
  my_strncpyx(res, gl, my_strlen(str), my_strlen(gl));
  return (res);
}

void	my_noneglob(t_data *data, my_ncurse *ncurse, char *str)
{
  int	i;

  i = -1;
  reset_shell_mode();
  my_putchar('\n');
  while (str[++i] != ' ' && str[i] != '\0')
    my_putchar(str[i]);
  my_putstr(": No match.\n");
  reset_prog_mode();
  my_prompt_ncurse(data, ncurse);
}
