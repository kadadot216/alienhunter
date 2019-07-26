SRC		=	./src/main.c			\
			./src/window.c			\
			./src/my_strdup.c		\
			./src/my_strlen.c		\
			./src/assets.c			\
			./src/rand_min_max.c		\
			./src/my_itoa.c			\
			./src/my_revstr.c		\
			./src/my_memset.c 		\
			./src/my_strcat.c 		\
			./src/player.c 			\
			./src/text.c 			\
			./src/my_putstr.c 		\
			./src/timer.c 			\
			./src/col.c 			\
			./src/events.c 			\
			./src/game.c 			\
			./src/alien.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude

NAME		=	hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		rm -f $(OBJ)


fclean:		clean
		rm -f $(NAME)

re:		fclean all
