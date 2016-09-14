##
## Makefile for Makefile in /home/thirie_a
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Mar 11 15:30:08 2016 jeremy thiriez
## Last update Thu Jul 21 18:41:21 2016 jeremy thiriez
##

NAME	= allum1

CC	= gcc

RM	= rm -rf

SRCS	= src/main.c \
	  src/my_show_map.c \
	  src/allum.c \
	  src/player.c \
	  src/ai.c \
	  src/iip.c \
	  src/ipi.c \
	  src/pii.c \
	  src/ppp.c \
	  src/last_mouve.c \
	  src/remove_matches.c \
	  src/check_all_line.c \
	  tools/my_show_int_tab.c \
	  tools/my_putstr.c \
	  tools/my_putchar.c \
	  tools/my_show_wordtab.c \
	  tools/my_put_nbr.c \
	  tools/my_getnbr.c \
	  tools/get_next_line.c

CFLAGS	+= -W -Wall -Wextra -I./include

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
