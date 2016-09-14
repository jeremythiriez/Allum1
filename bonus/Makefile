##
## Makefile for Makefile in /home/thirie_a
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Mar 11 15:30:08 2016 jeremy thiriez
## Last update Thu Jul 21 18:45:59 2016 jeremy thiriez
##

NAME	= allum1

CC	= gcc

RM	= rm -rf

LIB     = -L/home/${USER}/.froot/lib/ -llapin \
	  -L/usr/local/lib \
	  -lsfml-audio \
	  -lsfml-graphics \
	  -lsfml-window \
	  -lsfml-system \
	  -lstdc++ -ldl \
	  -lm -llapin


SRCS	= src/main.c \
	  src/create_game.c \
	  src/allum.c \
	  src/aff_matches.c \
	  src/key.c \
	  src/set_pos_pict.c \
	  src/load.c \
	  src/load_music.c \
	  src/menu.c \
	  src/mouse.c \
	  src/game_mouse.c \
	  src/again_mouse.c \
	  src/playing.c \
	  src/ai/ai.c \
	  src/ai/check_all_line.c \
	  src/ai/iip.c \
	  src/ai/ipi.c \
	  src/ai/last_mouve.c \
	  src/ai/pii.c \
	  src/ai/ppp.c \
	  src/ai/remove_matches.c

CFLAGS	+= -W -Wall -Wextra -I./include -g3

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
