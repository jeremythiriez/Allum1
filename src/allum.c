/*
** allum.c for allum.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Tue Jul 12 03:09:52 2016 Live session user
** Last update Thu Jul 21 17:13:28 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		tot_matches(t_all *all)
{
  int		tot;
  int		i;

  i = 0;
  tot = 0;
  while (i < 4)
    {
      tot = tot + all->nb_matches[i];
      i++;
    }
  return (tot);
}

int		allum(t_all *all)
{
  while (42)
    {
      if (all->turn_to_play == 0)
	{
	  if (player_play(all) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	ai_play(all);
      if (tot_matches(all) == 0)
	{
	  my_show_map(all->nb_matches);
	  if (all->turn_to_play == 0)
	    my_putstr(AI_LOSE);
	  else
	    my_putstr(YOU_LOSE);
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
