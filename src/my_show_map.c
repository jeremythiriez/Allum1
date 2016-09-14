/*
** my_show_map.c for my_show_map.c in /home/jeremy/rendu/CPE/test/CPE_2015_Allum1/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Jul 21 15:59:51 2016 jeremy thiriez
** Last update Thu Jul 21 17:06:21 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "allum1.h"

int		aff_pipe_or_space(int x, int y, int *matches)
{
  if (y == 0 || y == 5 || x == 0 || x == 8)
    my_putchar('*');
  else if (x > 0 && y > 0)
    {
      if (((y == 1 && x > 3) || (y == 2 && x > 2) || (y == 3 && x > 1) ||
	   (y == 4 && x > 0)) && *matches > 0)
	{
	  my_putchar('|');
	  *matches = *matches - 1;
	}
      else
	my_putchar(' ');
    }
  return (EXIT_SUCCESS);
}

int		my_show_map(int *tab)
{
  int		x;
  int		y;
  int		i;
  int		matches;

  y = 0;
  i = -1;
  matches = 0;
  while (y < 6)
    {
      x = 0;
      matches = tab[i];
      while (x < 9)
	{
	  aff_pipe_or_space(x, y, &matches);
	  x += 1;
	}
      my_putchar('\n');
      y += 1;
      i += 1;
    }
  return (EXIT_SUCCESS);
}
