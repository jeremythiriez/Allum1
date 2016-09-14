/*
** my_show_wordtab.c for my_show_wordtab.c in /home/thirie_a/rendu/Piscine_C_J08/ex_03
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed Mar  9 11:57:39 2016 jeremy thiriez
** Last update Wed Jul  6 23:15:28 2016 Live session user
*/

#include "allum1.h"

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
