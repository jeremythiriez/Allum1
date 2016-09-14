/*
** allum.c for allum.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 05:56:44 2016 jeremy thiriez
** Last update Thu Jul 21 18:45:43 2016 jeremy thiriez
*/

#include <unistd.h>
#include "allum1.h"

void				aff_end_pvp(t_all *all)
{
  if (all->bl.end_pvp == true)
    {
      end_pvp(all);
      bunny_display(all->bn.win);
      sleep(3);
      all->bl.again = true;
      all->bl.end_pvp = false;
    }
}

void				aff_end_pve(t_all *all)
{
  if (all->bl.end_pve == true)
    {
      end_pve(all);
      bunny_display(all->bn.win);
      sleep(3);
      all->bl.again = true;
      all->bl.end_pve = false;
    }
}

t_bunny_response		loop(void *data)
{
  t_all				*all;

  all = data;
  if (all->bl.begin == true)
    {
      begin(all);
      if (all->bl.m_menu == true)
	{
	  bunny_sound_play(&all->bn.m_menu->sound);
	  all->bl.m_menu = false;
	}
    }
  else if (all->bl.menu == true)
    menu(all);
  else if (all->bl.game == true)
    game(all);
  aff_end_pvp(all);
  aff_end_pve(all);
  play_again(all);
  if (all->bl.quit == true)
    quit(all);
  bunny_display(all->bn.win);
  return (GO_ON);
}
