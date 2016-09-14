/*
** get_next_line.c for get_next_line.c in /home/thirie_a/tech_1/GNL/CPE_2015_getnextline
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun  7 11:15:53 2016 jeremy thiriez
** Last update Sun Jun 19 17:11:32 2016 Live session user
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_realloc(char *str, int size_add)
{
  char		*tmp;
  int		size;
  int		i;

  size = 0;
  i = 0;
  while (str[size])
    size++;
  if ((tmp = malloc(sizeof(char) * (size + size_add + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = 0;
  free(str);
  return (tmp);
}

int		check_buff(char *buff, int data)
{
  int		j;

  j = 0;
  if (data == 0)
    while (buff[j])
      {
	buff[j] = buff[j + 1];
	j++;
      }
  else
    while (buff[j])
      j++;
  return (j);
}

char		*cpy_to_dest(t_gnl *gnl, char *buff)
{
  while (buff[0] != '\n' && buff[0] != 0)
    {
      gnl->dest[gnl->i] = buff[0];
      check_buff(buff, 0);
      gnl->i++;
    }
  gnl->dest[gnl->i] = 0;
  return (gnl->dest);
}

int		read_file(t_gnl *gnl, char *buff, const int fd)
{
  if (buff[0] == 0)
    {
      if ((gnl->ret = read(fd, buff, READ_SIZE)) <= 0)
	return (EXIT_FAILURE);
      buff[gnl->ret] = 0;
      if ((gnl->dest = my_realloc(gnl->dest, gnl->ret)) == NULL)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  t_gnl		gnl;
  int		test_macro;

  gnl.i = 0;
  gnl.ret = 1;
  test_macro = READ_SIZE;
  (void)test_macro;
  if ((gnl.dest = malloc(sizeof(char) * (check_buff(buff, 1) + 1))) == NULL)
    return (NULL);
  gnl.dest[0] = 0;
  while (buff[0] != '\n' && gnl.ret > 0)
    {
      if ((read_file(&gnl, buff, fd)) == EXIT_FAILURE)
	{
	  if (gnl.dest[0] != 0)
	    return (gnl.dest);
	  else
	    return (NULL);
	}
      gnl.dest = cpy_to_dest(&gnl, buff);
    }
  check_buff(buff, 0);
  return (gnl.dest);
}
