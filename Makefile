##
## Makefile for Makefile in /home/janel/Projects/templates/network/SYN_flooder
##
## Made by Janel
## Login   <XXX@epitech.eu>
##
## Started on  Tue Jul 12 12:19:34 2017 Janel
## Last update Mon Oct 23 00:26:55 2017 
##

SRC	= src/main.c \
	src/packet.c \
	src/checksum.c \
	src/send.c \

OBJ	= $(SRC:.c=.o)

NAME	= syn_flooder

RM	= rm -f

CC	= gcc -D_DEFAULT_SOURCE

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -ansi # -pedantic-errors
CFLAGS	+= -I./include
#CFLAGS	+= -ggdb3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
