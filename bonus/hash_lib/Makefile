##
## EPITECH PROJECT, 2023
## my_organize
## File description:
## my_organize
##

NAME	=	libhashtable.a

CFLAGS	=	-Wshadow -Wall -I./include -lcsfml-window -lcsfml-graphics \
			-lcsfml-system -lcsfml-audio -lcsfml-network

SRC		=	my_strlen.c		\
			my_getnbr.c	\
			my_put_nbr.c	\
			my_strcpy.c		\
			my_strdup.c		\
			my_positive_nbr.c \
			mini_printf.c		\
			my_putchar.c	\
			my_putstr.c		\
			my_strcmp.c		\
			my_unsigned_nbr.c	\
			my_compute_power_rec.c 	\
			delete_key.c	\
			delete.c	\
			dump.c	\
			hash.c		\
			insert.c	\
			new_hash.c	\
			search.c	\
			pf.c		\
			my_intlen.c 		\
			my_hover_effect.c	\
			my_itoa.c

OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp libhashtable.a ../
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

clean:
			rm -f $(OBJ)
			rm -f *.gc*
			rm -f coding-style-reports.log
			rm -f *~
			rm -f *.gcda
			rm -f *.gcno
			rm -f *.o
			rm -f libhashtable.a
			echo -e "\e[1;33m{ Library as been cleaned }\e[00;37m"

fclean:	clean
			rm -f $(NAME)
			echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"


re:	fclean all
