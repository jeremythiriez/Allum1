/*
** my_getnbr.c for my_getnbr.c in /home/thirie_a/rendu/Piscine_C_J04
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Fri Mar  4 12:20:12 2016 jeremy thiriez
** Last update Thu Jul 21 18:31:30 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "allum1.h"

int	my_check(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_putstr(BAD_INP);
	  return (-1);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

int		my_getnbr(char *str)
{
  int		i;
  int		result;

  i = 0;
  result = 0;
  if (str[0] == 0)
    {
      my_putstr(BAD_INP);
      return (-2);
    }
  if (my_check(str) == -1)
    return (-2);
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      result = (result * 10) + (str[i] - 48);
      i = i + 1;
    }
  return (result);
}
