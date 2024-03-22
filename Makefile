##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC     =	src/my_putchar.c	\
		src/my_putstr.c	\
		src/separator.c	\
		src/info.c	\
		src/n4.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all :	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -lm $(OBJ)

clean :
	rm -f $(OBJ)

fclean :clean
	rm -f $(NAME)

re :	fclean all
