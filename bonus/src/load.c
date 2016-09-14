/*
** load.c for load.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 06:20:01 2016 jeremy thiriez
** Last update Thu Jul 21 18:49:29 2016 jeremy thiriez
*/

#include "allum1.h"

int		set_bool(t_all *all)
{
  all->bl.begin = true;
  all->bl.menu = false;
  all->bl.game = false;
  all->bl.quit = false;
  all->bl.again = false;
  all->bl.end_pvp = false;
  all->bl.end_pve = false;
  all->bl.end_game = false;
  all->bl.pvp = true;
  all->bl.pve = true;
  all->bl.yes = true;
  all->bl.no = true;
  all->bl.play = true;
  all->bl.start = true;
  all->bl.ok = true;
  all->bl.set_line = true;
  all->bl.turn_to_play = true;
  all->bn.b_start[0].aff = false;
  all->bl.g_pvp = false;
  all->bl.g_pve = false;
  all->bl.m_menu = true;
  all->bl.m_playing = true;
  return (EXIT_SUCCESS);
}

int		load_pic_button(t_all *all)
{
  if ((all->bn.b_play[0].pic =
       bunny_load_picture("pictures/Play1.png")) == NULL ||
      (all->bn.b_play[1].pic =
       bunny_load_picture("pictures/Play2.png")) == NULL ||
      (all->bn.b_pvp[0].pic =
       bunny_load_picture("pictures/button_pvp1.png")) == NULL ||
      (all->bn.b_pvp[1].pic =
       bunny_load_picture("pictures/button_pvp2.png")) == NULL ||
      (all->bn.b_pve[0].pic =
       bunny_load_picture("pictures/button_pve1.png")) == NULL ||
      (all->bn.b_pve[1].pic =
       bunny_load_picture("pictures/button_pve2.png")) == NULL ||
      (all->bn.b_ok[0].pic =
       bunny_load_picture("pictures/Ok1.png")) == NULL ||
      (all->bn.b_ok[1].pic =
       bunny_load_picture("pictures/Ok2.png")) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		loat_pic_button_next(t_all *all)
{
  if ((all->bn.b_no[0].pic =
       bunny_load_picture("pictures/No1.png")) == NULL ||
      (all->bn.b_no[1].pic =
       bunny_load_picture("pictures/No2.png")) == NULL ||
      (all->bn.b_yes[0].pic =
       bunny_load_picture("pictures/Yes1.png")) == NULL ||
      (all->bn.b_yes[1].pic =
       bunny_load_picture("pictures/Yes2.png")) == NULL ||
      (all->bn.player_play[0].pic =
       bunny_load_picture("pictures/player_1_play.png")) == NULL ||
      (all->bn.player_play[1].pic =
       bunny_load_picture("pictures/player_2_play.png")) == NULL ||
      (all->bn.player_play[2].pic =
       bunny_load_picture("pictures/ai_play.png")) == NULL ||
      (all->bn.b_start[0].pic =
       bunny_load_picture("pictures/Start1.png")) == NULL ||
      (all->bn.b_start[1].pic =
       bunny_load_picture("pictures/Start2.png")) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		load_picture(t_all *all)
{
  if ((all->bn.begin = bunny_load_picture("pictures/Begin.png")) == NULL ||
      (all->bn.menu = bunny_load_picture("pictures/Menu.png")) == NULL ||
      (all->bn.quit = bunny_load_picture("pictures/Quit.png")) == NULL ||
      (all->bn.game = bunny_load_picture("pictures/Game.png")) == NULL ||
      (all->bn.p_one_win = bunny_load_picture("pictures/P2win.png")) == NULL ||
      (all->bn.p_two_win = bunny_load_picture("pictures/P1win.png")) == NULL ||
      (all->bn.p_again = bunny_load_picture("pictures/p_again.png")) == NULL ||
      (all->bn.you_win = bunny_load_picture("pictures/you_win.png")) == NULL ||
      (all->bn.ai_win = bunny_load_picture("pictures/ai_win.png")) == NULL ||
      (load_pic_button(all) == EXIT_FAILURE) ||
      (loat_pic_button_next(all) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		load_bunny(t_all *all)
{
  int		i;

  i = 0;
  if (((all->bn.win = bunny_start(WIDTH, HEIGHT, 0, "Allum1")) == NULL)
      || (all->bn.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL
      || (load_picture(all) == EXIT_FAILURE)
      || (load_music(all) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  set_bool(all);
  set_pos_pic(all);
  set_pos_pic_next(all);
  while (i < 16)
    {
      all->bn.mat[i].pic = bunny_load_picture("pictures/matches.png");
      i++;
    }
  return (EXIT_SUCCESS);
}
