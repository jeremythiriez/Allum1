/*
** create_game.c for create_game.c in /home/mint/rendu/CPE/CPE_2015_Allum1/src
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Wed Jul  6 22:50:20 2016 Live session user
** Last update Tue Jul 12 06:13:09 2016 Live session user
*/

#include <stdlib.h>
#include "allum1.h"

int		malloc_game(t_all *all)
{
  int		y;

  y = 0;
  if ((all->game = malloc(sizeof(char *) * (6 + 1))) == NULL)
    return (EXIT_FAILURE);
  while (y < 6)
    {
      if ((all->game[y] = malloc(sizeof(char) * (9 + 1))) == NULL)
	return (EXIT_FAILURE);
      y += 1;
    }
  return (EXIT_SUCCESS);
}

int		put_matches(t_all *all)
{
  int		x;
  int		y;
  int		begin_x;
  int		matches;

  y = 1;
  begin_x = 4;
  while (y < 5)
    {
      matches = 0;
      x = begin_x;
      while (matches < all->nb_matches[y - 1])
	{
	  all->game[y][x] = '|';
	  x += 1;
	  matches += 1;
	}
      begin_x -= 1;
      y += 1;
    }
  return (EXIT_SUCCESS);
}

int		make_plate(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < 6)
    {
      x = 0;
      while (x < 9)
	{
	  if (x == 0 || y == 0 || x == 8 || y == 5)
	    all->game[y][x] = '*';
	  else
	    all->game[y][x] = ' ';
	  x += 1;
	}
      all->game[y][x] = 0;
      y += 1;
    }
  all->game[y] = 0;
  put_matches(all);
  return (EXIT_SUCCESS);
}
