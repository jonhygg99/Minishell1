##
## EPITECH PROJECT, 2018
##
## File description:
##
##

SRC	=	src/main.c	\
		lib/my_strcat.c	\
		lib/get_next_line.c	\
		src/point_2_pointer.c	\
		src/command_base.c	\
		src/find_bin.c	\
		src/change_directory.c	\
		src/environment_settings.c	\
		src/search_home.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_strlen.c	\
		lib/my_strcmp.c	\

CFLAGS	=	-g3

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
