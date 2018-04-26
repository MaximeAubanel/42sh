/*
** echo.c for  in /home/rozier_s/rendu/C_elem/PSU_2015_42sh
**
** Made by simon ROZIER
** Login   <rozier_s@epitech.net>
**
** Started on  Wed May 25 20:14:49 2016 simon ROZIER
** Last update Tue Jun 07 14:42:45 2016 Maxime Aubanel
*/

#include "my.h"

t_echo	fun[] =
  {
    {"\\", &my_backslash},
    {"$", &my_fenv},
    {"-n", &my_line},
    {NULL, NULL}
  };

char	*custom_epur(char *str, char c, int k)
{
  char	*res;
  int	i;
  int	j;
  int	a;

  a = 0;
  i = -1;
  j = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) - k + 1))) == NULL)
    return (NULL);
  while (str[++i] != '\0')
    {
      if (str[i] != c)
	{
	  res[j] = str[i];
	  j += 1;
	  a = a + 1;
	}
    }
  res[j] = '\0';
  return (res);
}

char	**echo_check(char *str)
{
  int	i;
  int	k;
  char	c;

  i = -1;
  k = 0;
  while (str[++i] != '\0')
    {
      if (k == 0 && (str[i] == '\'' || str[i] == '"'))
	{
	  c = str[i];
	  k += 1;
	}
      else if (k > 0 && str[i] == c)
	    k = k + 1;
	}
      if (k % 2 == 1)
    {
      printf("Unmatched %c.\n", c);
      return (NULL);
    }
  if (k > 0)
    return (str_to_wordtab(custom_epur(str, c, k)));
  else
    return (str_to_wordtab(normalize_str(str)));
}

int	init_echo(t_data *data, t_d *val)
{
  val->i = -1;
  val->saut = 0;
  val->opt = -1;
  if ((val->tab =
       echo_check(data->exec.cmd_nrml + my_size(data->exec.cmd_nrml))) == NULL)
    {
      reset_prog_mode();
      return (-1);
    }
  return (0);
}

void	my_echo(t_data *data, char *str)
{
  t_d	val;

  reset_shell_mode();
  if (str == NULL)
    {
      my_putchar('\n');
      reset_prog_mode();
      return ;
    }
    if (init_echo(data, &val) == -1)
    exit(0);
  while (val.tab[++val.i] != NULL && ++val.opt < 1000)
    {
      val.j = -1;
      while (fun[++val.j].str != NULL &&
	     my_find(fun[val.j].str, val.tab[val.i]) != 0);
      if (fun[val.j].str != NULL)
	fun[val.j].fct(data, &val);
      else
	write(1, val.tab[val.i], my_strlen(val.tab[val.i]));
      if (val.tab[val.i + 1] != NULL && val.opt > -1)
	write(1, " ", 1);
    }
  if (val.saut == 0)
	my_putchar('\n');
}
