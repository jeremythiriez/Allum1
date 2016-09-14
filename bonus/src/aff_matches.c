/*
** aff_matches.c for aff_matches.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Jul 14 23:00:00 2016 jeremy thiriez
** Last update Thu Jul 21 15:01:30 2016 jeremy thiriez
*/

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

int		set_matches(t_all *all)
{
  int		x;
  int		y;
  int		i;

  y = 1;
  i = 0;
  while (y < 5)
    {
      x = 1;
      while (x < 8)
	{
	  if (all->game[y][x] == '|')
	    {
	      all->bn.mat[i].pos.x = x * 120 + 200;
	      all->bn.mat[i].pos.y = y * 250 - 150;
	      all->bn.mat[i].y = y;
	      all->bn.mat[i].aff = true;
	      i += 1;
	    }
	  x += 1;
	}
      y += 1;
    }
  return (EXIT_SUCCESS);
}

int		aff_matches(t_all *all)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      if (all->bn.mat[i].aff == true)
	bunny_blit(&all->bn.win->buffer,
		   all->bn.mat[i].pic, &all->bn.mat[i].pos);
      i += 1;
    }
  return (EXIT_SUCCESS);
}
