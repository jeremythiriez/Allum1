/*
** allum1.h for allum1.h in /home/mint/rendu/CPE/CPE_2015_Allum1/include
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 22:30:33 2016 Live session user
** Last update Thu Jul 21 14:01:26 2016 jeremy thiriez
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

# define WIDTH 1425
# define HEIGHT 1450

# include <lapin.h>
# include <stdbool.h>

typedef struct		s_mat
{
  bool			aff;
  t_bunny_position	pos;
  int			y;
  t_bunny_picture	*pic;
}			t_mat;

typedef struct		s_bunny
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_mat			mat[16];
  t_mat			b_play[2];
  t_mat			b_pvp[2];
  t_mat			b_pve[2];
  t_mat			b_no[2];
  t_mat			b_yes[2];
  t_mat			b_start[2];
  t_mat			b_ok[2];
  t_mat			player_play[3];
  t_bunny_picture	*begin;
  t_bunny_picture	*menu;
  t_bunny_picture	*game;
  t_bunny_picture	*quit;
  t_bunny_picture	*p_one_win;
  t_bunny_picture	*p_two_win;
  t_bunny_picture	*you_win;
  t_bunny_picture	*ai_win;
  t_bunny_picture	*p_again;
  t_bunny_music		*m_playing;
  t_bunny_music		*m_menu;
  t_bunny_music		*m_bip;
}			t_bunny;

typedef struct		s_bool
{
  bool			begin;
  bool			menu;
  bool			quit;
  bool			again;
  bool			game;
  bool			end_game;
  bool			end_pvp;
  bool			end_pve;
  bool			play;
  bool			start;
  bool			pvp;
  bool			pve;
  bool			yes;
  bool			no;
  bool			ok;
  bool			g_pvp;
  bool			g_pve;
  bool			player_vs_player;
  bool			turn_to_play;
  bool			set_line;
  bool			m_playing;
  bool			m_menu;
}			t_bool;

typedef struct		s_all
{
  int			step;
  int			line;
  int			matches;
  int			nb_matches[4];
  char			**game;
  t_bunny		bn;
  t_bool		bl;
}			t_all;

typedef struct		s_fonc
{
  int			sit;
  int			(*fonc)(t_all *all);
}			t_fonc;

int			allum(t_all *all);
int			player_play(t_all *all);
int			malloc_game(t_all *all);
int			make_plate(t_all *all);
int			ai_play(t_all *all);

char			*get_next_line(const int fd);
void			my_putchar(char c);
int			my_putstr(char *str);
void			my_show_wordtab(char **tab);
int			my_put_nbr(int nb);
int			my_getnbr(char *str);
void			my_show_int_tab(int *tab, int size);


int			init_allum(t_all *all);
int			load_bunny(t_all *all);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mouse_button but,
			      void *data);
int			set_matches(t_all *all);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data);
t_bunny_response	loop(void *data);
int			begin(t_all *all);
int			menu(t_all *all);
int			game(t_all *all);
int			quit(t_all *all);
int			set_pos_pic(t_all *all);
int			set_pos_pic_next(t_all *all);
int			aff_matches(t_all *all);
t_bunny_response	remove_matches(t_bunny_event_state state,
				       t_bunny_mouse_button but,
				       t_all *all);
t_bunny_response	game_mouse(t_bunny_event_state state,
				   t_bunny_mouse_button but,
				   t_all *all);
t_bunny_response	again_mouse(t_bunny_event_state state,
				   t_bunny_mouse_button but,
				   t_all *all);
int			playing(t_all *all);
int			tot_matches(t_all *all);
int			end_pvp(t_all *all);
int			end_pve(t_all *all);
int			play_again(t_all *all);
int			set_bool(t_all *all);

int                     pi_and_ppi(t_all *all);
int                     pip(t_all *all);
int                     ipp(t_all *all);
int                     iii(t_all *all);
int                     ppi(t_all *all);
int                     pii(t_all *all);
int                     iip(t_all *all);
int                     ipi(t_all *all);
int                     ppp(t_all *all);

int                     check_all_line(t_all *all);
int                     less_one_matches(t_all *all);

int                     one_matches_per_line(t_all *all);
int                     remove_all_line_or_less_one_mat(t_all *all);
int			load_music(t_all *all);
int			del_music(t_all *all, int i);

#endif /* !ALLUM1_H_ */
