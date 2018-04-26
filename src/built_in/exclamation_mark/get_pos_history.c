/*
** get_pos_history.c for PSU_2015_42sh in /home/deforg_a/Documents/rendu/PSU/PSU_2015_42sh/src/built_in/exclamation_mark
**
** Made by deforges
** Login   <deforg_a@epitech.net>
**
** Started on  Sat Jun 04 04:17:42 2016 deforges
** Last update Sun Jun 05 07:15:20 2016 deforges
*/

 #include "my.h"

 char		*my_change(t_data *data, char *cmd, char *mark)
{
  char		*cmd_hist;
  int		pos;

  pos = 0;
  cmd_hist = NULL;
  if (neg_zero(mark) == 0)
    {
      pos = get_pos(mark);
      cmd_hist = get_cmd(data, mark, pos);
    }
  if (check_error(data, mark, pos) == 0)
    cmd = completion(cmd, cmd_hist, mark);
  else
    cmd = event_not_found(data, cmd, mark, pos);
  return (cmd);
}

 int		get_pos_positiv(char *mark)
 {
   char		*num;
   int		pos;
   int		i;
   int		e;

   i = 0;
   e = -1;
   if ((num = malloc(sizeof(char) * (my_strlen(mark)))) == NULL)
     return (0);
   bzero(num, my_strlen(mark));
   while (mark && mark[++i])
     num[++e] = mark[i];
   pos = atoi(num);
   free(num);
   return (pos);
 }

 int		get_pos_neg(char *mark)
 {
   char		*num;
   int		pos;
   int		i;
   int		e;

   i = 1;
   e = -1;
   if ((num = malloc(sizeof(char) * (my_strlen(mark)))) == NULL)
     return (0);
   bzero(num, my_strlen(mark));
   while (mark && mark[++i])
     num[++e] = mark[i];
   pos = atoi(num);
   free(num);
   return (pos);
 }

 int		get_pos(char *mark)
 {
   int		i;
   int		pos;

   i = -1;
   while (mark && mark[++i])
     {
       if (mark[i] == '!' && mark[i + 1] == '-')
 	pos = get_pos_neg(mark);
       else if (mark[i] == '!')
 	pos = get_pos_positiv(mark);
     }
   return (pos);
 }
