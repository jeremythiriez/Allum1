/*
** mouse.c for mouse.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 09:26:27 2016 jeremy thiriez
** Last update Mon Jul 25 00:42:08 2016 jeremy thiriez
*/

#include "allum1.h"

t_bunny_response		begin_mouse(t_bunny_event_state state,
					    t_bunny_mouse_button but,
					    t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT && mouse->x >= 451 &&
      mouse->x <= 937 && mouse->y >= 665 && mouse->y <= 864)
    {
      all->bl.play = false;
      bunny_sound_play(&all->bn.m_bip->sound);
    }
  if (state == GO_UP)
    all->bl.play = true;
  if (state == GO_UP && but == BMB_LEFT && mouse->x >= 451 &&
      mouse->x <= 937 && mouse->y >= 665 && mouse->y <= 864)
    {
      all->bl.begin = false;
      all->bl.menu = true;
      all->bl.play = true;
    }
  return (GO_ON);
}

t_bunny_response		but_start(t_bunny_event_state state,
					  t_bunny_mouse_button but,
					  t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT && mouse->x >= 486 &&
      mouse->x <= 905 && mouse->y >= 927 && mouse->y <= 1083)
    {
      all->bl.start = false;
      bunny_sound_play(&all->bn.m_bip->sound);
    }
  if (state == GO_UP)
    all->bl.start = true;
  if (state == GO_UP && but == BMB_LEFT && mouse->x >= 486 &&
      mouse->x <= 905 && mouse->y >= 927 && mouse->y <= 1083)
    {
      if (all->bl.pve == false)
	all->bl.g_pve = true;
      else if (all->bl.pvp == false)
	all->bl.g_pvp = true;
      all->bl.menu = false;
      all->bl.start = true;
      all->bn.b_start[0].aff = false;
      all->bl.game = true;
    }
  return (GO_ON);
}

t_bunny_response		menu_mouse(t_bunny_event_state state,
					    t_bunny_mouse_button but,
					    t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT &&  mouse->x >= 167 &&
      mouse->x <= 431 && mouse->y >= 709 && mouse->y <= 805)
    {
      all->bl.pvp = false;
      all->bl.pve = true;
      all->bn.b_start[0].aff = true;
      bunny_sound_play(&all->bn.m_bip->sound);
    }
  if (state == GO_DOWN && but == BMB_LEFT && mouse->x >= 966 &&
      mouse->x <= 1231 && mouse->y >= 710 && mouse->y <= 804)
    {
      all->bl.pve = false;
      all->bl.pvp = true;
      all->bn.b_start[0].aff = true;
      bunny_sound_play(&all->bn.m_bip->sound);
    }
  if (all->bn.b_start[0].aff == true)
    but_start(state, but, all);
  return (GO_ON);
}

t_bunny_response		quit_mouse(t_bunny_event_state state,
					    t_bunny_mouse_button but,
					    t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT &&  mouse->x >= 206 &&
      mouse->x <= 309 && mouse->y >= 781 && mouse->y <= 841)
    all->bl.yes = false;
  if (state == GO_UP)
    all->bl.yes = true;
  if (state == GO_UP && but == BMB_LEFT && mouse->x >= 206 &&
      mouse->x <= 309 && mouse->y >= 781 && mouse->y <= 841)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && but == BMB_LEFT && mouse->x >= 1006 &&
      mouse->x <= 1109 && mouse->y >= 782 && mouse->y <= 842)
    all->bl.no = false;
  if (state == GO_UP)
    all->bl.no = true;
  if (state == GO_UP && but == BMB_LEFT && mouse->x >= 1006 &&
      mouse->x <= 1109 && mouse->y >= 782 && mouse->y <= 842)
    {
      all->bl.no = true;
      all->bl.game = true;
    }
  return (GO_ON);
}

t_bunny_response		click(t_bunny_event_state state,
				      t_bunny_mouse_button but,
				      void *data)
{
  t_all				*all;

  all = data;
  if (all->bl.begin == true)
    begin_mouse(state, but, all);
  else if (all->bl.menu == true)
    menu_mouse(state, but, all);
  else if (all->bl.game == true)
    {
      if (all->bl.g_pvp == true)
	game_mouse(state, but, all);
      else if (all->bl.g_pve == true && all->bl.turn_to_play == true)
	game_mouse(state, but, all);
      else
	ai_play(all);
    }
  else if (all->bl.again == true)
    again_mouse(state, but, all);
  else if (all->bl.quit == true)
    if (quit_mouse(state, but, all) == EXIT_ON_SUCCESS)
      {
	del_music(all, 2);
	return (EXIT_ON_SUCCESS);
      }
  return (GO_ON);
}
