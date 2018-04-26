/*
** cmd.h for PSU_2015_42sh in /home/aubane_m/rendu/PSU/PSU_2015_42sh/include
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Apr 27 13:17:17 2016 Maxime Aubanel
** Last update Sun Jun  5 13:49:03 2016 Bartosz Truchlewski
*/

/*######################################*/
/*###############           ###########*/
/*##############CMD_HISTORY############*/
/*#############           ############*/
/*###################################*/

typedef struct		s_cmd
{
  char			*str;
  struct s_cmd		*next;
  struct s_cmd		*prev;
  char			*timer;
  int			x;
}			t_cmd;

typedef	struct		s_list_cmd
{
  t_cmd			*head;
  t_cmd			*tail;
  int			size;
}			t_list_cmd;

typedef	struct		my_cmd
{
  char			*cmd;
  char			*epur_cmd;
  int			x;
  int			nb;
}			my_cmd;

void			init_list_double(t_list_cmd **list);
void			display_list_double(t_list_cmd *list);
void			first_ini_double(t_list_cmd *list, char *str, int x);
void			end_list_double(t_list_cmd *list, char *str, int x);
char			*my_time();
