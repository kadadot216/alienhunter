##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my_hunter
##

SRC		=	main.c		\
			window.c	\
			./lib/my/my_strdup.c	\
			assets.c		\
			rand_min_max.c		\
			my_itoa.c		\
			my_revstr.c		\
			my_memset.c 	\
			my_strcat.c 	\
			player.c 	\
			text.c 	\
			my_putstr.c 	\
			game.c 	\
			alien.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude

NAME		=	my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		rm -f $(OBJ)


fclean:		clean
		rm -f $(NAME)

re:		fclean all
