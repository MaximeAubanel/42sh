/*
** my.h for my.h in /home/aubane_m/rendu/PSU/PSU_2015_42sh
**
** Made by Maxime Aubanel
** Login   <aubane_m@epitech.net>
**
** Started on  Wed Jun  1 22:25:35 2016 Maxime Aubanel
** Last update Tue Jun 07 16:19:48 2016 Maxime Aubanel
*/


#ifndef _42SH_H_
# define _42SH_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "cmd.h"
#include "lib.h"
#include "my_ncurse.h"

/*##################################*/
/*########## STRUCT LIST ###########*/
/*##################################*/

typedef struct		s_node
{
  char			*data;
  struct s_node		*left;
  struct s_node		*right;
  struct s_node		*root;
}			t_node;

typedef struct		s_elem
{
  char			*str;
  struct s_elem		*next;
}			t_elem;

typedef struct		s_list
{
  t_elem		*head;
  t_elem		*tail;
  int			size;
}			t_list;


typedef	struct		s_priority
{
  t_elem		*head;
  int			size;
}			t_priority;

/*######################################*/
/*nor###############           ###########*/
/*############## STRUCTURE ############*/
/*#############           ############*/
/*###################################*/

typedef struct		s_exec
{
  char			*cmd_str;
  char			*cmd_nrml;
  char			**arg;
  char			**path_tab;
  char			**env;
  char			*access;
  char			*path;
  char			*old_pwd;
}			t_exec;


typedef struct		s_dup
{
  int			redirect;
  int			indirect;
  int			mode;
}			t_dup;

/*####################################*/
/*############ STRUCT_ENV ###########*/
/*####################################*/

typedef	struct		s_env
{
  char			*pwd;
  char			*oldpwd;
}			t_env;

/*####################################*/
/*############ STRUCT_PIPE ###########*/
/*####################################*/

typedef struct		s_pipe
{
  int			fd1;
  int			fd2;
  int			mode;
}			t_pipe;

/*####################################*/
/*############ STRUCT_ALIAS ###########*/
/*####################################*/

typedef struct		s_alias
{
  char			*cmd;
  char			*alias;
  char			*param;
}			t_alias;

/*####################################*/
/*############ STRUCT_BASHRC ###########*/
/*####################################*/

typedef struct		s_bashrc
{
  t_alias		*alias;
}			t_bashrc;

/*####################################*/
/*############# MAIN_STRUCT ##########*/
/*####################################*/

typedef struct		s_data
{
  t_priority		my_priority;
  t_exec		exec;
  t_list		my_list;
  t_node		*bin;
  t_dup			dup;
  t_env			env;
  t_pipe		pipe;
  t_list_cmd		*cmd;
  pid_t			pid_f;
  int			status;
  my_cmd		my_cmd;
  my_ncurse		ncurse;
  t_bashrc		bashrc;
  int			bashrc_ex;
  int			last_pos;
  int			nb;
  bool			mark;
  bool			mark_alone;
  bool			isnum;
  char			*copy;
  int			my_exit;
}			t_data;

typedef struct		s_buildin
{
  char			*str;
  void			(*action)(t_data *data, char *str);
}			t_buildin;

typedef struct		tokenPtr
{
  char *flag;
  int (*fct)(t_data *data, t_node *);
}			tokenPtr;

typedef struct		s_pid
{
  pid_t			pid1;
  pid_t			pid2;
  int			status;
}			t_pid;

void			lauch_42sh_ncurse(t_data *data, my_ncurse *ncurse);
void			my_prompt();
int			check_alias_execution(t_data *data, char *cmd);

int	my_2find(char *first, char *end, char *match, char c);
char    **my_str_to_wordtab(char *str, char c, int len);

char			*normalize_str(char *str);
char			*add_a_char(char *str, char c);
int			my_init(t_data *data, char *str);
void			execution(t_data *data);
void			my_cd(t_data *data, char *str);
void			my_env(t_data *data, char *str);
void			my_exit(t_data *data, char *str);
int			function_fork(t_data *data);
void			execution(t_data *data);
char			*check_access(char **tab);
char			*PATH_to_str(char **env);
int			check_PATH(char **env, char *str);
char			**add_in_tab(char **tab, char *str);
char			**realloc_tab(char **tab, int nbr_char);
void			display_wordtab(char **tab);
void			build_unsetenv(char *str, char **arg, char **env);
char			*HOME_to_str(char **env);
void			build_cd(t_data *data);
int			find_in_env(char *name, char **env);
void			modif_env_cd(t_data *data, char *oldpwd);
int			check_env_exist(t_data *data, t_list *list, char *str);
void			find_token_ext(char *str, int *i);

/*############ LIST ##########*/

void			init_list(t_list **list);
void			first_ini(t_list *list, char *str);
void			top_list(t_list *list, char *str);
void			end_list(t_list *list, char *str);
void			display_list(t_list *list);
void			delete_list(t_list *list, int pos);
void			change_list(t_list *list, char *str, int pos);
char			**list_in_chartab(t_list *list);
t_list			*tab_in_list(t_list *list, char **env);

void			display_tree(t_data *data, t_node *root);
void			my_tree(t_data *data, char *str);
int			exectree(t_data *data, t_node *node);
t_node			*build_tree(char *str);
char			*getfieldenv(t_list *list, char *str);
char			*check_access(char **tab);
void			 check_dup(t_data *data);
void			check_pipe(t_data *data, int x);
void			lauch_ncurse(t_data *data, my_ncurse *ncurse);
int			check_ch(t_data *data, int ch);
void			init_ncurse(t_data *data, my_ncurse *ncurse);


void			new_env_null(t_data *data);
void			new_env(t_data *data);

/*############ BUIT_IN ##########*/

/*----BUILT_ECHO-----*/
typedef struct          s_d
{
  int                   i;
  int                   j;
  char                  **tab;
  int                   saut;
  int                   opt;
  int                   k;
}                       t_d;

typedef struct          s_echo
{
  char                  *str;
  void                  (*fct)(t_data *data, t_d *val);
}                       t_echo;

void			my_echo(t_data *data, char *str);
char    		**echo_check(char *str);
char    		*custom_epur(char *str, char c, int k);
void    		my_line(t_data *data, t_d *val);
void    		my_fenv(t_data *data, t_d *val);
void    		my_star(t_data *data, t_d *val);
void    		echo_list(t_list *list);
int     		my_match(char *str, char *mat, char c);
int     		my_find(char *ts, char *str);
int     		the_nsame(char *str, char *val);
void    		my_backslash(t_data *data, t_d *val);
int     		my_size(char *str);
char    		*my_crochstar(char *str);
void    		my_strncpyx(char *str, char *val, int nb, int size);
char    		*my_glob(char *str);
char    		*my_globing(char *str);
void    		my_changestr(char **str, char c, char k);
char			*my_customiz(char *str, int k);
int			c_str_len(char *str, char c, int k);
void			my_noneglob(t_data *data, my_ncurse *ncurse,
				    char *str);
void 			my_2print(char *str, char c);
int			*my_init_var(int val);

/*----BUILT_HISTORY-----*/

void			my_history(t_data *data, char *str);
void			put_in_history(t_data *data, char *str, char *timer, int x);
void			my_history_cmd(t_data *data, char *str);
char			*history_search(t_data *data, int x);
void			print_history_key(t_data *data, int y);

/*----BUILT_HISTORY_EXCLAMATION-----*/
char			*get_exclamation(char *cmd);
int			get_pos_positiv(char *mark);
int			get_pos_neg(char *mark);
char			*get_cmd_positiv(t_data *data, int pos);
char			*get_cmd_neg(t_data *data, int pos);
char			*change_cmd(t_data *data, char *cmd);
char			*delet_mark(char *str, char *mark);
int			neg_zero(char *mark);
int			check_one_mark(char *str);
int			check_mark(char *str);
int			check_if_history(char *str);
int			check_error(t_data* data, char *mark, int pos);
char			*get_cmd(t_data *data, char *mark, int pos);
int			get_pos(char *mark);
char			*first_mark_history(t_data *data, char *str);
void			my_print_cmd(t_data *data, char *cmd);
char			*my_change(t_data *data, char *cmd, char *mark);
char			*event_not_found(t_data *data, char *cmd, char *mark, int pos);

/*----BUILT_SETENV-UNSETENV-----*/

void			my_setenv(t_data *data, char *str);
void			modif_setenv(t_data *data, int x);
void			my_unsetenv(t_data *data, char *str);

/*##################################*/
/*########### TOKEN_FUNCTION ########*/
/*##################################*/

int			semicolon(t_data *data, t_node *node);

int			my_pipe(t_data *data, t_node *node);

int			simple_redir_left(t_data *data, t_node *node);
int			simple_redir_right(t_data *data, t_node *node);
int			double_redir_right(t_data *data, t_node *node);

int			my_dupdup(t_data *data, t_node *node, int i);
int			my_dupdup_indir(t_data *data, t_node *node, int i);
int			my_open_redir_right(t_data *data, t_node *node);
int			my_open_double_redir_right(t_data *data, t_node *node);
int			my_open_redir_left(t_data *data, t_node *node);



extern tokenPtr arrayToken[];

/*##################################*/
/*############ KEY MANAGEMENT ###########*/
/*##################################*/

void			key_right(t_data *data);
void			key_up(t_data *data);
void			key_delete(t_data *data);
void			key_down(t_data *data);
void			key_left(t_data *data);
void			key_ctrl_a(t_data *data);
void			key_ctrl_y(t_data *data);
void			key_ctrl_k(t_data *data);
void			key_ctrl_e(t_data *data);
void			key_ctrl_l(t_data *data);
void			key_ctrl_d(t_data *data);
void			key_tab(t_data *data);
/*---KEY_TAB_EXT1.C---*/
void			modify_cmd(t_data *ata, char *name, char *word);
char			*completion(char *com, char *new, char *cmp);
char			*mallocNewCom(char **tab_com, char *new, int i);
char			*getNewCom(char **tab_com, char *new,
				   int i, char *new_com);
void			display_all(t_data *data);
/*---KEY_TAB_EXT2.C---*/
char			*return_word(t_data *data);
char			*my_revstr(char *str);
int			display_glob(char **glob, t_data *data, char *word);
char			*add_end_star(char *str);

void			my_prompt_ncurse(t_data *data, my_ncurse *ncurse);

/*##################################*/
/*############# CMD_MANAGEMENT ###########*/
/*##################################*/

char			*add_ch_in_line(my_ncurse *ncurse, int ch, char *str);
void			my_backspace();
char			*add_line(char *str, char ch, my_ncurse *ncurse);

extern bool		check_exec;
int			and(t_data *, t_node *);
int			or(t_data *, t_node *);
void			check_exec_error(int signum);

/*##################################*/
/*############# CHECH_ALIAS #############*/
/*##################################*/

int			check_if_alias(t_data *data, char *cmd);
void			check_alias_exec(t_data *data);
char			**check_alias(t_data *data, char **tab, int x);

typedef struct		s_key
{
  int			key;
  void 			(*fct)(t_data *data);
}			t_key;

/*##################################*/
/*############# AUTO_COMPLETION ##########*/
/*##################################*/

char			*completion(char *com, char *new, char *cmp);
void			init_bashrc(t_data *data);
void			lauch_is_atty(t_data *data);
void			my_cmd_exec(t_data *data, my_ncurse *ncurse);

#endif /* !_42SH_H_*/
