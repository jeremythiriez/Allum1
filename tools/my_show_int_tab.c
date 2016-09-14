/*
** my_show_int_tab.c for my_show_int_tab.c in /home/mint/rendu/CPE/CPE_2015_Allum1/tools
**
** Made by Live session user
** Login   <mint@epitech.net>
**
** Started on  Tue Jul 12 04:26:47 2016 Live session user
** Last update Tue Jul 12 04:28:08 2016 Live session user
*/

#include "allum1.h"

void		my_show_int_tab(int *tab, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      my_put_nbr(tab[i]);
      my_putchar(' ');
      i++;
    }
}
