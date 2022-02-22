##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = my_sokoban

CC    = gcc

RM    = rm -f

SRC    = main.c								\
		 ./src/actualise.c					\
		 ./src/movement.c					\
		 ./src/my_str_to_word_array.c		\
		 ./src/read.c						\
		 ./src/sokoban.c					\

OBJ    = $(SRC:.c=.o)

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lncurses

all: $(NAME)

$(NAME):
	cd ./lib/my/ && make
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all
