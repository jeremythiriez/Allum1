/*
** my_putchar.c for my_putchar.c in /home/thirie_a/rendu/fonctions
** 
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
** 
** Started on  Tue Mar  8 10:19:05 2016 jeremy thiriez
** Last update Tue Mar  8 10:20:00 2016 jeremy thiriez
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
