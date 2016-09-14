/*
** last_mouve.c for last_mouve.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Jul 20 18:45:31 2016 jeremy thiriez
** Last update Wed Jul 20 20:16:55 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		one_matches_per_line(t_all *all)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < 4)
    {
      if (all->nb_matches[i] > 1)
	j += 1;
      i += 1;
    }
  return (j);
}

int		pair_matches(t_all *all)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < 4)
    {
      if (all->nb_matches[i] == 1)
	j += 1;
      i += 1;
    }
  return (j);
}

int		remove_all_line_or_less_one_mat(t_all *all)
{
  int		i;

  i = 0;
  all->line = 0;
  while (all->line == 0)
    {
      if (all->nb_matches[i] > 1 && one_matches_per_line(all) > 0)
	{
	  all->line = i + 1;
	  if (pair_matches(all) % 2 == 0)
	    all->matches = all->nb_matches[i] - 1;
	  else
	    all->matches = all->nb_matches[i];
	}
      else if (one_matches_per_line(all) == 0)
	if (all->nb_matches[i] == 1)
	  {
	    all->line = i + 1;
	    all->matches = 1;
	  }
      i += 1;
    }
  return (EXIT_FAILURE);
}
