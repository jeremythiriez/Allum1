/*
** remove_matches.c for remove_matches.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 21:20:29 2016 jeremy thiriez
** Last update Wed Jul 20 20:05:07 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		pi_and_ppi(t_all *all)
{
  int		i;

  i = 0;
  all->matches = 1;
  while (i < 4)
    {
      if (all->nb_matches[i] % 2 == 1)
	{
	  all->line = i + 1;
	  break;
	}
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		pip(t_all *all)
{
  int		i;

  all->matches = 2;
  all->line = 0;
  while (all->line == 0)
    {
      i = rand() % 4;
      if (all->nb_matches[i] == 2 || all->nb_matches[i] == 3 ||
	  all->nb_matches[i] == 6 || all->nb_matches[i] == 7)
	all->line = i + 1;
    }
  return (EXIT_SUCCESS);
}

int		ipp(t_all *all)
{
  int		i;

  all->matches = 4;
  all->line = 0;
  while (all->line == 0)
    {
      i = rand() % 4;
      if (all->nb_matches[i] == 4 || all->nb_matches[i] == 5 ||
	  all->nb_matches[i] == 6 || all->nb_matches[i] == 7)
	all->line = i + 1;
    }
  return (EXIT_SUCCESS);
}

int		iii(t_all *all)
{
  int		i;

  i = 0;
  all->matches = 1;
  all->line = 0;
  while (all->line == 0)
    {
      if (all->nb_matches[i] == 4)
	all->line = i + 1;
      else if (all->nb_matches[i] == 7)
	{
	  all->matches = 7;
	  all->line = i + 1;
	}
      else if (all->nb_matches[i] == 5)
	{
	  all->matches = 3;
	  all->line = i + 1;
	}
      i += 1;
    }
  return (EXIT_SUCCESS);
}
