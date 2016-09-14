/*
** iip.c for iip.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 23:06:45 2016 jeremy thiriez
** Last update Thu Jul 21 14:59:53 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

static int	rand_zero(t_all *all, int i)
{
  all->matches = 6;
  while (i < 4)
    {
      if (all->nb_matches[i] == 6 || all->nb_matches[i] == 7)
	all->line = i + 1;
      i += 1;
    }
  return (EXIT_SUCCESS);
}

static int	rand_one(t_all *all, int i)
{
  all->matches = 2;
  while (i < 4)
    {
      if (all->nb_matches[i] == 4 || all->nb_matches[i] == 5)
	all->line = i + 1;
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		iip(t_all *all)
{
  int		random;
  int		i;

  all->line = 0;
  while (all->line == 0)
    {
      i = 0;
      random = rand() % 2;
      if (random == 0)
	rand_zero(all, i);
      else if (random == 1)
	rand_one(all, i);
    }
  return (EXIT_SUCCESS);
}
