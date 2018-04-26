/*
** ncurse.c for le42 in /home/aubane_m/rendu/PSU/le42/src/ncurse
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Mon May 02 20:57:33 2016 Maxime Aubanel
** Last update Tue Jun 07 15:07:47 2016 Maxime Aubanel
*/

#include "my.h"

int 	signal_c = 0;

int			check_cmd(char *cmd)
{
  if (my_strcmp(cmd, "\n") == 0)
    return (-1);
  return (0);
}

void			my_ctrl()
{
  signal_c = 1;
  reset_shell_mode();
  my_putstr("\n$->");
  reset_prog_mode();
}

void			cmd_init(t_data *data, my_ncurse *ncurse)
{
  if (data->my_cmd.cmd == NULL)
    my_prompt_ncurse(data, ncurse);
  else
    my_cmd_exec(data, ncurse);
}

void			lauch_42sh_ncurse(t_data *data, my_ncurse *ncurse)
{
  int			ch;

  ch = 0;
  signal(SIGINT, my_ctrl);
  init_ncurse(data, ncurse);
  while (42)
    {
      ch = getch();
      if (ch == '\n')
	cmd_init(data, ncurse);
      else if (check_ch(data, ch) == -1)
	{
	  insch(ch);
	  data->my_cmd.cmd = add_line(data->my_cmd.cmd, ch, ncurse);
          key_right(data);
	}
    }
  endwin();
}
