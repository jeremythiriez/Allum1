/*
** allum.c for allum.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 23:41:40 2016 Live session user
** Last update Thu Jul 21 21:28:09 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int		line(t_all *all)
{
  my_putstr(LINE);
  if ((all->gnl = get_next_line(0)) == NULL)
    return (EXIT_FAILURE);
  if ((all->line = my_getnbr(all->gnl)) == -2)
    return (-1);
  if (all->line < 1 || all->line > 4)
    {
      my_putstr(ER_LINE);
      return (-1);
    }
  if (all->nb_matches[all->line - 1] == 0)
    {
      my_putstr(LINE_UMP);
      return (-1);
    }
  all->step = 2;
  return (EXIT_SUCCESS);
}

int		matches(t_all *all)
{
  my_putstr(MATCHES);
  if ((all->gnl = get_next_line(0)) == NULL)
    return (EXIT_FAILURE);
  if ((all->matches = my_getnbr(all->gnl)) == -2)
    {
      all->step = 1;
      return (-1);
    }
  if (all->matches == 0)
    {
      my_putstr(M_0);
      all->step = 1;
      return (-1);
    }
  if (all->matches > all->nb_matches[all->line - 1])
    {
      my_putstr(ER_MAT);
      all->step = 1;
      return (-1);
    }
  all->step = 3;
  return (EXIT_SUCCESS);
}

int		exec_play(t_all *all)
{
  if (all->step == 4)
    {
      all->nb_matches[all->line - 1] -= all->matches;
      all->turn_to_play = 1;
    }
  return (EXIT_SUCCESS);
}

int		action(t_all *all)
{
  my_putstr(P_R);
  my_put_nbr(all->matches);
  my_putstr(MAT_L);
  my_put_nbr(all->line);
  my_putchar('\n');
  all->step = 4;
  return (EXIT_SUCCESS);
}

int		player_play(t_all *all)
{
  if (all->step == 0)
    {
      my_show_map(all->nb_matches);
      my_putchar('\n');
      my_putstr(YOU_PLAY);
      all->step = 1;
    }
  else if (all->step == 1)
    {
      if (line(all) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (all->step == 2)
    {
      if (matches(all) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (all->step == 3)
    action(all);
  exec_play(all);
  return (EXIT_SUCCESS);
}
