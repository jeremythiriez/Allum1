/*
** ppp.c for ppp.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Jul 20 16:24:57 2016 jeremy thiriez
** Last update Wed Jul 20 16:30:00 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		ppp(t_all *all)
{
  int		i;

  i = 0;
  all->matches = 1;
  while (all->line == 0)
    {
      if (all->nb_matches[i] == 1)
	all->line = i + 1;
      i += 1;
    }
  return (EXIT_SUCCESS);
}
