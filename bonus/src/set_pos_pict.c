/*
** set_pos_pict.c for set_pos_pic.c in /home/jeremy/rendu/CPE/CPE_2015_Allum1/bonus/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Fri Jul 15 06:25:40 2016 jeremy thiriez
** Last update Sun Jul 24 23:32:27 2016 jeremy thiriez
*/

#include "allum1.h"

int		set_pos_pic(t_all *all)
{
  all->bn.b_play[0].pos.x = 370;
  all->bn.b_play[0].pos.y = 600;
  all->bn.b_play[1].pos.x = 370;
  all->bn.b_play[1].pos.y = 600;
  all->bn.b_pvp[0].pos.x = 150;
  all->bn.b_pvp[0].pos.y = 700;
  all->bn.b_pvp[1].pos.x = 150;
  all->bn.b_pvp[1].pos.y = 700;
  all->bn.b_pve[0].pos.x = 950;
  all->bn.b_pve[0].pos.y = 700;
  all->bn.b_pve[1].pos.x = 950;
  all->bn.b_pve[1].pos.y = 700;
  all->bn.b_ok[0].pos.x = 600;
  all->bn.b_ok[0].pos.y = 960;
  all->bn.b_ok[1].pos.x = 600;
  all->bn.b_ok[1].pos.y = 960;
  return (EXIT_SUCCESS);
}

int		set_pos_pic_next(t_all *all)
{
  all->bn.b_yes[0].pos.x = 150;
  all->bn.b_yes[0].pos.y = 700;
  all->bn.b_yes[1].pos.x = 150;
  all->bn.b_yes[1].pos.y = 700;
  all->bn.b_no[0].pos.x = 950;
  all->bn.b_no[0].pos.y = 700;
  all->bn.b_no[1].pos.x = 950;
  all->bn.b_no[1].pos.y = 700;
  all->bn.b_start[0].pos.x = 450;
  all->bn.b_start[0].pos.y = 900;
  all->bn.b_start[1].pos.x = 450;
  all->bn.b_start[1].pos.y = 900;
  all->bn.player_play[0].pos.x = 170;
  all->bn.player_play[0].pos.y = 300;
  all->bn.player_play[1].pos.x = 1000;
  all->bn.player_play[1].pos.y = 300;
  all->bn.player_play[2].pos.x = 1000;
  all->bn.player_play[2].pos.y = 300;
  return (EXIT_SUCCESS);
}
