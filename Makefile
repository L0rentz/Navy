##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	navy

CC	=	gcc

SRC	=	src/my_utils.c \
		src/my_utils2.c \
		src/pid_signal.c \
		src/attack_signal.c \
		src/confirmation_signal.c \
		src/player_turn.c \
		src/printer.c \
		src/main.c \
		src/load_map.c \
		src/error.c \
		src/parse_file.c \
		src/get_next_line.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
