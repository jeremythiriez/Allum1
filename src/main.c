/*
** main.c for main.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 22:32:16 2016 Live session user
** Last update Thu Jul 21 18:40:47 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <time.h>
#include "allum1.h"

int		set_nb_matches(t_all *all)
{
  int		i;
  int		j;

  i = 0;
  j = 1;
  while (i < 4)
    {
      all->nb_matches[i] = j;
      j += 2;
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		init_allum(t_all *all)
{
  all->step = 0;
  all->turn_to_play = 0;
  srand(time(NULL));
  return (EXIT_SUCCESS);
}

int		main(void)
{
  t_all		all;

  init_allum(&all);
  set_nb_matches(&all);
  if (allum(&all) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
