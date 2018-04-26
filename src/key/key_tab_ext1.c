/*
** key_tab_ext1.c for key_tab in /home/truchl_b/rendu/PSU/PSU_2015_42sh
**
** Made by Bartosz Truchlewski
** Login   <truchl_b@epitech.net>
**
** Started on  Sat Jun  4 14:24:11 2016 Bartosz Truchlewski
** Last update Tue Jun 07 15:57:56 2016 Maxime Aubanel
*/

#include "my.h"
#include "glob.h"

void		display_all(t_data *data)
{
  int		i;
  glob_t	myglob;

  i = 0;
  my_putchar('\n');
  glob("*", GLOB_NOCHECK | GLOB_MARK, NULL, &myglob);
  while (myglob.gl_pathv[i])
    {
      my_putstr(myglob.gl_pathv[i]);
      my_putchar('\t');
      i = i + 1;
    }
  my_putchar('\n');
  my_putstr("$->");
  if (data->my_cmd.cmd !=  NULL)
    my_putstr(data->my_cmd.cmd);
}

char	*getNewCom(char **tab_com, char *new, int i, char *new_com)
{
  int	j;
  int	k;
  int	l;

  j = -1;
  l = 0;
  while (tab_com[++j])
    {
      k = 0;
      if (j == i)
        {
          while (new[k])
            new_com[l++] = new[k++];
        }
      else
        {
          while (tab_com[j][k])
            new_com[l++] = tab_com[j][k++];
        }
      if (tab_com[j + 1] == NULL)
        new_com[l] = '\0';
      else
        new_com[l++] = ' ';
    }
  return (new_com);
}

char	*mallocNewCom(char **tab_com, char *new, int i)
{
  char  *new_com;
  int   j;
  int   nb_malloc;

  j = 0;
  nb_malloc = 0;
  while (tab_com[j])
    {
      if (j == i)
        nb_malloc = nb_malloc + my_strlen(new) + 1;
      else
        nb_malloc = nb_malloc + my_strlen(tab_com[j]);
      if (tab_com[j + 1] != NULL)
        nb_malloc += 1;
      j += 1;
    }
  if ((new_com = malloc(sizeof(char) * nb_malloc)) == NULL)
    exit(EXIT_FAILURE);
  return (new_com);
}

char	*completion(char *com, char *new, char *cmp)
{
  char  **tab_com;
  char  *new_com;
  int   i;

  i = 0;
  tab_com = str_to_wordtab(com);
  while (tab_com[i])
    {
      if (my_strncmp(tab_com[i], cmp, my_strlen(tab_com[i])) == 0)
        {
          new_com = mallocNewCom(tab_com, new, i);
          new_com = getNewCom(tab_com, new, i, new_com);
          return (new_com);
        }
      else
        i += 1;
    }
  return (NULL);
}

void	modify_cmd(t_data *data, char *name, char *word)
{
  int	y;
  int	x;

  getyx(stdscr, y, x);
  mvinsstr(y, x, my_revstrncpy(name, my_strlen(word) - 1));
  data->my_cmd.cmd = completion(data->my_cmd.cmd, name, word);
  move(y, my_strlen(data->my_cmd.cmd) + 3);
}
