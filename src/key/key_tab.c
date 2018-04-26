/*
** key_tab.c for le42 in /home/aubane_m/rendu/PSU/le42/src/key
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 12 16:37:25 2016 Maxime Aubanel
** Last update Tue Jun 07 15:57:58 2016 Maxime Aubanel
*/

#include "my.h"
#include "glob.h"

void			find_completion(t_data *data)
{
  char			*word;
  glob_t		my_glob;

  word = normalize_str(return_word(data));
  glob(word, GLOB_NOCHECK | GLOB_MARK, NULL, &my_glob);
  if (my_strcmp(my_glob.gl_pathv[0], word) != 0 && my_glob.gl_pathv[1] == NULL)
    modify_cmd(data, my_glob.gl_pathv[0], word);
}

char			*parse_tab(char *str)
{
  char			*new;
  int 			i;

  i = 0;
  while (str[i] != '/')
    i = i + 1;
  new = my_revstrncpy(str, i + 1);
  return (new);
}

void			display_in(char **tab, t_data *data)
{
  int			i;

  i = 0;
  my_putchar('\n');
  while (tab[i])
    {
      my_putstr(parse_tab(tab[i]));
      my_putchar('\t');
      i = i + 1;
    }
  my_putchar('\n');
  my_putstr("$->");
  if (data->my_cmd.cmd !=  NULL)
    my_putstr(data->my_cmd.cmd);
}

void			display_inside(t_data *data)
{
  char			*word;
  glob_t		my_glob;

  word = normalize_str(return_word(data));
  glob(word, GLOB_NOCHECK | GLOB_MARK, NULL, &my_glob);
  if (my_strcmp(my_glob.gl_pathv[0], word) != 0 && my_glob.gl_pathv[1] == NULL)
    modify_cmd(data, my_glob.gl_pathv[0], word);
  else
    display_in(my_glob.gl_pathv, data);
}

void			key_tab(t_data *data)
{
  int			x;
  int			y;
  char			c;

  (void)data;
  getyx(data->ncurse.win, y, x);
  c = (char)mvinch(y, x - 1);
  move(y, x);
  reset_shell_mode();
  if (c == ' ' || c == '>')
    display_all(data);
  else if (c == '/')
    display_inside(data);
  else
    find_completion(data);
  reset_prog_mode();
}
