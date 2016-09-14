/*
** main.c for main.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 22:32:16 2016 Live session user
** Last update Thu Jul 21 15:02:12 2016 jeremy thiriez
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
  set_nb_matches(all);
  make_plate(all);
  set_matches(all);
  return (EXIT_SUCCESS);
}

int		main(void)
{
  t_all		all;

  if (malloc_game(&all) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_allum(&all);
  if (load_bunny(&all) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  bunny_set_click_response(click);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(loop);
  bunny_loop(all.bn.win, 60, &all);
  return (EXIT_SUCCESS);
}
