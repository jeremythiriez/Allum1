/*
** again_mouse.c for mouse_again.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 15:20:48 2016 jeremy thiriez
** Last update Thu Jul 21 15:01:52 2016 jeremy thiriez
*/

#include "allum1.h"

t_bunny_response		no(const t_bunny_position *mouse,
				   t_bunny_event_state state,
				   t_bunny_mouse_button but,
				   t_all *all)
{
  if (state == GO_DOWN && but == BMB_LEFT &&
      mouse->x >= 1006 && mouse->x <= 1109 &&
      mouse->y >= 782 && mouse->y <= 842)
    all->bl.no = false;
  if (state == GO_UP)
    all->bl.no = true;
  if (state == GO_UP && but == BMB_LEFT &&
      mouse->x >= 1006 && mouse->x <= 1109 &&
      mouse->y >= 782 && mouse->y <= 842)
    {
      all->bl.no = true;
      all->bl.quit = true;
      all->bl.again = false;
    }
  return (GO_ON);
}

t_bunny_response		again_mouse(t_bunny_event_state state,
					    t_bunny_mouse_button but,
					    t_all *all)
{
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  if (state == GO_DOWN && but == BMB_LEFT &&
      mouse->x >= 206 && mouse->x <= 309 &&
      mouse->y >= 781 && mouse->y <= 841)
    all->bl.yes = false;
  if (state == GO_UP)
    all->bl.yes = true;
  if (state == GO_UP && but == BMB_LEFT &&
      mouse->x >= 206 && mouse->x <= 309 &&
      mouse->y >= 781 && mouse->y <= 841)
    {
      set_bool(all);
      all->bl.begin = false;
      all->bl.menu = true;
      init_allum(all);
    }
  no(mouse, state, but, all);
  return (GO_ON);
}
