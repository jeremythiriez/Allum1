/*
** allum1.h for allum1.h in /home/mint/rendu/CPE/CPE_2015_Allum1/include
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 22:30:33 2016 Live session user
** Last update Thu Jul 21 18:31:48 2016 jeremy thiriez
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

# define AI_PLAY "AI's turn...\n"
# define YOU_PLAY "Your turn:\n"
# define MAT_L " match(es) from line "
# define P_R "Player removed "
# define AI_R "AI removed "
# define LINE "Line: "
# define MATCHES "Matches: "
# define ER_LINE "Error: this line is out of range\n"
# define LINE_UMP "Error: this line is empty\n"
# define BAD_INP "Error: invalid input (positive number expected)\n"
# define M_0 "Error: you have to remove at least one match\n"
# define ER_MAT "Error: not enough matches on this line\n"
# define YOU_LOSE "You lost, too bad..\n"
# define AI_LOSE "I lost.. snif.. but I'll get you next time!!\n"

# include <stdbool.h>

typedef struct		s_all
{
  char			*gnl;
  int			step;
  int			line;
  int			matches;
  int			nb_matches[4];
  bool			turn_to_play;
}			t_all;

typedef struct		s_fonc
{
  int			sit;
  int			(*fonc)(t_all *all);
}			t_fonc;

int			allum(t_all *all);
int			player_play(t_all *all);
int			ai_play(t_all *all);
char			*get_next_line(const int fd);
void			my_putchar(char c);
int			my_putstr(char *str);
int			my_put_nbr(int nb);
int			my_getnbr(char *str);
int			pi_and_ppi(t_all *all);
int			pip(t_all *all);
int			ipp(t_all *all);
int			iii(t_all *all);
int			ppi(t_all *all);
int			pii(t_all *all);
int			iip(t_all *all);
int			ipi(t_all *all);
int			ppp(t_all *all);
int			check_all_line(t_all *all);
int			less_one_matches(t_all *all);
int			one_matches_per_line(t_all *all);
int			remove_all_line_or_less_one_mat(t_all *all);
int			my_show_map(int *tab);

#endif /* !ALLUM1_H_ */
