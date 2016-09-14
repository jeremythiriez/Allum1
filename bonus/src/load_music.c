/*
** load_music.c for load_music.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Jul 21 13:02:20 2016 jeremy thiriez
** Last update Thu Jul 21 21:28:40 2016 jeremy thiriez
*/

#include "allum1.h"

int		del_music(t_all *all, int i)
{
  if (i >= 0)
    bunny_delete_sound(&all->bn.m_menu->sound);
  if (i >= 1)
    bunny_delete_sound(&all->bn.m_bip->sound);
  return (EXIT_FAILURE);
}

int		load_music(t_all *all)
{
  if ((all->bn.m_menu = bunny_load_music("music/zelda.wav")) == NULL)
    return (del_music(all, 1));
  if ((all->bn.m_bip = bunny_load_music("music/bip4.wav")) == NULL)
    return (del_music(all, 2));
  return (EXIT_SUCCESS);
}
