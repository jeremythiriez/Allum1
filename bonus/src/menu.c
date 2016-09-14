/*
** menu.c for menu.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 08:22:17 2016 jeremy thiriez
** Last update Thu Jul 21 14:41:14 2016 jeremy thiriez
*/

#include "allum1.h"

int		begin(t_all *all)
{
  bunny_blit(&all->bn.win->buffer, all->bn.begin, NULL);
  if (all->bl.play == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_play[0].pic,
	       &all->bn.b_play[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_play[1].pic,
	       &all->bn.b_play[1].pos);
  return (EXIT_SUCCESS);
}

int		menu(t_all *all)
{
  bunny_blit(&all->bn.win->buffer, all->bn.menu, NULL);
  if (all->bl.pvp == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_pvp[0].pic,
	       &all->bn.b_pvp[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_pvp[1].pic,
	       &all->bn.b_pvp[1].pos);
  if (all->bl.pve == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_pve[0].pic,
	       &all->bn.b_pve[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_pve[1].pic,
	       &all->bn.b_pve[1].pos);
  if (all->bn.b_start[0].aff == true)
    {
      if (all->bl.start == true)
	bunny_blit(&all->bn.win->buffer, all->bn.b_start[0].pic,
		   &all->bn.b_start[0].pos);
      else
	bunny_blit(&all->bn.win->buffer, all->bn.b_start[1].pic,
		   &all->bn.b_start[1].pos);
    }
  return (EXIT_SUCCESS);
}

int		game(t_all *all)
{
  bunny_blit(&all->bn.win->buffer, all->bn.game, NULL);
  if (all->bl.ok == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_ok[0].pic,
	       &all->bn.b_ok[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_ok[1].pic,
	       &all->bn.b_ok[1].pos);
  playing(all);
  aff_matches(all);
  return (EXIT_SUCCESS);
}

int		quit(t_all *all)
{
  bunny_blit(&all->bn.win->buffer, all->bn.quit, NULL);
  if (all->bl.yes == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_yes[0].pic,
	       &all->bn.b_yes[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_yes[1].pic,
	       &all->bn.b_yes[1].pos);
  if (all->bl.no == true)
    bunny_blit(&all->bn.win->buffer, all->bn.b_no[0].pic,
	       &all->bn.b_no[0].pos);
  else
    bunny_blit(&all->bn.win->buffer, all->bn.b_no[1].pic,
	       &all->bn.b_no[1].pos);
  return (EXIT_SUCCESS);
}

int		play_again(t_all *all)
{
  if (all->bl.again == true)
    {
      bunny_blit(&all->bn.win->buffer, all->bn.p_again, NULL);
      if (all->bl.yes == true)
	bunny_blit(&all->bn.win->buffer, all->bn.b_yes[0].pic,
		   &all->bn.b_yes[0].pos);
      else
	bunny_blit(&all->bn.win->buffer, all->bn.b_yes[1].pic,
		   &all->bn.b_yes[1].pos);
      if (all->bl.no == true)
	bunny_blit(&all->bn.win->buffer, all->bn.b_no[0].pic,
		   &all->bn.b_no[0].pos);
      else
	bunny_blit(&all->bn.win->buffer, all->bn.b_no[1].pic,
		   &all->bn.b_no[1].pos);
    }
  return (EXIT_SUCCESS);
}
