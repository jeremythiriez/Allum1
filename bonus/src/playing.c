/*
** pvp.c for pvp.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 11:30:34 2016 jeremy thiriez
** Last update Thu Jul 21 11:39:19 2016 jeremy thiriez
*/

#include "allum1.h"

int		end_pvp(t_all *all)
{
  if (all->bl.turn_to_play == false)
    bunny_blit(&all->bn.win->buffer, all->bn.p_one_win, NULL);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.p_two_win, NULL);
  return (EXIT_SUCCESS);
}

int		end_pve(t_all *all)
{
  if (all->bl.turn_to_play == false)
    bunny_blit(&all->bn.win->buffer, all->bn.ai_win, NULL);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.you_win, NULL);
  return (EXIT_SUCCESS);
}

int		playing(t_all *all)
{
  if (all->bl.end_game == false)
    {
      if (all->bl.turn_to_play == true)
	bunny_blit(&all->bn.win->buffer, all->bn.player_play[0].pic,
		   &all->bn.player_play[0].pos);
      else
	{
	  if (all->bl.g_pvp == true)
	    bunny_blit(&all->bn.win->buffer, all->bn.player_play[1].pic,
		       &all->bn.player_play[1].pos);
	  else if (all->bl.g_pve == true)
	    bunny_blit(&all->bn.win->buffer, all->bn.player_play[2].pic,
		       &all->bn.player_play[2].pos);
	}
    }
  else
    {
      all->bl.game = false;
      if (all->bl.g_pvp == true)
	all->bl.end_pvp = true;
      else if (all->bl.g_pve == true)
	all->bl.end_pve = true;
    }
  return (EXIT_SUCCESS);
}
