##
## EPITECH PROJECT, 2024
## B-CPE-110-NAN-1-1-secured-albane.merian
## File description:
## Makefile
##

CC	=	gcc

NAME	=	secured

UNIT_TEST = test

CFLAGS	=	-g -Wshadow -Werror -I./include

CRIT_FLAG	=	--coverage -lcriterion

LIBS	=	-L ./ -lhashtable

SRC		=   main.c	\

SRC_TEST =	hash_lib/my_strlen.c		\
			hash_lib/my_getnbr.c	\
			hash_lib/my_put_nbr.c	\
			hash_lib/my_strdup.c		\
			hash_lib/my_positive_nbr.c \
			hash_lib/mini_printf.c 		\
			hash_lib/pf.c 				\
			hash_lib/my_intlen.c 		\
			hash_lib/my_putchar.c	\
			hash_lib/my_putstr.c		\
			hash_lib/my_strcpy.c		\
			hash_lib/my_strcmp.c			\
			hash_lib/my_unsigned_nbr.c	\
			hash_lib/my_compute_power_rec.c 	\
			hash_lib/delete_key.c	\
			hash_lib/delete.c	\
			hash_lib/dump.c	\
			hash_lib/hash.c		\
			hash_lib/insert.c	\
			hash_lib/new_hash.c	\
			hash_lib/search.c

TEST	= 	tests/test_squared.c		\
			tests/test_getnbr.c			\
			tests/test_positive.c		\
			tests/test_strdup.c 		\
			tests/test_strcpy.c			\
			tests/test_strcmp.c			\
			tests/test_destroy.c		\
			tests/test_dump.c			\
			tests/test_insert.c			\
			tests/test_search.c			\
			tests/test_printf.c			\
			tests/test_number.c			\
			tests/test_delete.c

OBJ		=	$(SRC:.c=.o)

all:	libmaking $(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS) -I ./include
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"


.PHONY: libmaking

libmaking:
			$(MAKE) -C hash_lib

$(UNIT_TEST): fclean all
	$(CC) -o $(UNIT_TEST) $(SRC_TEST) $(TEST) $(CRIT_FLAG) $(LIBS)

tests_run: $(UNIT_TEST)
		@./$(UNIT_TEST)
		@gcovr --exclude tests/

clean:
			$(MAKE) -C hash_lib clean
			rm -f $(OBJ)
			rm -f *.gc*
			rm -f coding-style-reports.log
			rm -f *~
			rm -f *.gcda
			rm -f *.gcno
			rm -f secured
			rm -f unit_tests
			rm -f libhashtable.a
			rm -f test

fclean:	clean
			$(MAKE) -C hash_lib fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"


re:	fclean all
