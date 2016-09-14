/*
** key.c for key.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Jul 14 23:18:11 2016 jeremy thiriez
** Last update Fri Jul 15 10:43:36 2016 jeremy thiriez
*/

#include "allum1.h"

t_bunny_response		key(t_bunny_event_state state,
				    t_bunny_keysym sym,
				    void *data)
{
  t_all				*all;

  (void)state;
  (void)data;
  all = data;
  if (sym == BKS_ESCAPE)
    {
      all->bl.begin = false;
      all->bl.menu = false;
      all->bl.game = false;
      all->bl.quit = true;
    }
  return (GO_ON);
}
