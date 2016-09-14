/*
** remove_matches.c for remove_matches.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 11:48:10 2016 jeremy thiriez
** Last update Thu Jul 21 11:04:12 2016 jeremy thiriez
*/

#include "allum1.h"

int				my_remove(const t_bunny_position *mouse,
					  t_all *all,
					  int i)
{
  if (mouse->x >= all->bn.mat[i].pos.x &&
      mouse->x <= all->bn.mat[i].pos.x + 30 &&
      mouse->y >= all->bn.mat[i].pos.y &&
      mouse->y <= all->bn.mat[i].pos.y + 180 &&
      tot_matches(all) > 0)
    {
      if (all->bl.set_line == true)
	{
	  all->bl.set_line = false;
	  all->line = all->bn.mat[i].y;
	}
      if (all->bn.mat[i].y == all->line && all->bn.mat[i].aff == true)
	{
	  all->bn.mat[i].aff = false;
	  all->nb_matches[all->line - 1] -= 1;
	}
    }
  return (EXIT_SUCCESS);
}

t_bunny_response		remove_matches(t_bunny_event_state state,
					       t_bunny_mouse_button but,
					       t_all *all)
{
  const t_bunny_position	*mouse;
  int				i;

  i = 0;
  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT)
    {
      while (i < 16)
	{
	  my_remove(mouse, all, i);
	  i += 1;
	}
    }
  return (GO_ON);
}

t_bunny_response		game_mouse(t_bunny_event_state state,
					   t_bunny_mouse_button but,
					   t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  remove_matches(state, but, all);
  if (state == GO_DOWN && but == BMB_LEFT &&
      mouse->x >= 657 && mouse->x <= 760 &&
      mouse->y >= 1042 && mouse->y <= 1102)
    all->bl.ok = false;
  if (state == GO_UP)
    all->bl.ok = true;
  if (state == GO_UP && but == BMB_LEFT && mouse->x >= 657
      && mouse->x <= 760 && mouse->y >= 1042
      && mouse->y <= 1102 && all->bl.set_line == false)
    {
      if (tot_matches(all) <= 0)
	all->bl.end_game = true;
      if (all->bl.turn_to_play == true)
	all->bl.turn_to_play = false;
      else
	all->bl.turn_to_play = true;
      all->bl.set_line = true;
      all->bl.ok = true;
    }
  return (GO_ON);
}
