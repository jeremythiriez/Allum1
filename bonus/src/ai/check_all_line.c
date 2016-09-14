/*
** check_all_line.c for check_all_line.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Jul 20 17:40:50 2016 jeremy thiriez
** Last update Wed Jul 20 18:23:49 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		check_all_line(t_all *all)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < 4)
    {
      if (all->nb_matches[i] > 0)
	j += 1;
      i += 1;
    }
  return (j);
}

int		less_one_matches(t_all *all)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (all->nb_matches[i] > 1)
	{
	  all->line = i + 1;
	  all->matches =
	    all->nb_matches[i] - (all->nb_matches[i] - 1);
	}
      else if (all->nb_matches[i] == 1)
	{
	  all->line = i + 1;
	  all->matches = 1;
	}
      i += 1;
    }
  return (EXIT_SUCCESS);
}
