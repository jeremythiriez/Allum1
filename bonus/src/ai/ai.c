/*
** ai.c for ai.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Tue Jul 12 06:02:49 2016 Live session user
** Last update Thu Jul 21 11:00:54 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

static const t_fonc	g_tab[] =
  {
    {21, &pi_and_ppi},
    {221, &pi_and_ppi},
    {222, &ppp},
    {212, &pip},
    {122, &ipp},
    {211, &pii},
    {121, &ipi},
    {112, &iip},
    {111, &iii},
  };

int		find_situation(int nb)
{
  int		result;
  int		i;
  int		j;

  i = 0;
  j = 100;;
  result = 0;
  while (i < 3)
    {
      if (((nb / j) % 2) == 0)
	result = result * 10 + 2;
      else if (((nb / j) % 2) == 1)
	result = result * 10 + 1;
      nb %= j;
      j /= 10;
      i += 1;
    }
  return (result);
}

int		calc_situation(t_all *all)
{
  int		i;
  int		save;
  int		result;
  int		bin;

  bin = 2;
  result = 0;
  while (bin >= 0)
    {
      save = 0;
      i = 0;
      while (i < 4)
	{
	  if (((all->nb_matches[i] >> bin) & 1) == 1)
	    save += 1;
	  i += 1;
	}
      result = result * 10 + save;
      bin -= 1;
    }
  return (result);
}

int		algo(t_all *all)
{
  int		sit;
  int		i;

  i = 0;
  if (check_all_line(all) != 1)
    {
      if (one_matches_per_line(all) > 1)
	{
	  sit = find_situation(calc_situation(all));
	  while (i < 9)
	    {
	      if (sit == g_tab[i].sit)
		g_tab[i].fonc(all);
	      i += 1;
	    }
	}
      else
	remove_all_line_or_less_one_mat(all);
    }
  else
    less_one_matches(all);
  return (EXIT_SUCCESS);
}

int		remove_matches_ai(t_all *all)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      if (all->bn.mat[i].y == all->line
	  && all->bn.mat[i].aff == true
	  && all->matches > 0)
	{
	  all->bn.mat[i].aff = false;
	  all->matches -= 1;
	}
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		ai_play(t_all *all)
{
  algo(all);
  all->nb_matches[all->line - 1] -= all->matches;
  remove_matches_ai(all);
  all->bl.turn_to_play = true;
  //  sleep(1);
  return (EXIT_SUCCESS);
}
