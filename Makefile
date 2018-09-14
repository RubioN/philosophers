##
## EPITECH PROJECT, 2018
## makefile
## File description:
## malloc
##

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g3 -I./include

LDFLAGS	= -L. -lriceferee -lpthread

RM = rm -f

NAME = philo

SRC =	src/main.c		\
	src/init.c		\
	src/philo_algo.c	\
	src/algo.c		\
	src/error.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re
