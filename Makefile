##
## Makefile for Makefile in /home/janel/Projects/templates/network/SYN_flooder
##
## Made by Nicolas Giannelos
## Login   <gianne_n@epitech.net>
##
## Started on  Tue Jul 12 12:19:34 2017 Nicolas Giannelos
## Last update Mon May 29 16:29:40 2017 Janel
##

SRC	= src/main.c \
	src/network_miscellaneous.c \
	src/packet.c \

OBJ	= $(SRC:.c=.o)

NAME	= syn_flooder

RM	= rm -f

CC	= gcc -std=c99

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -ansi # -pedantic-errors
CFLAGS	+= -I./include
CFLAGS	+= -g3 -ggdb3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
