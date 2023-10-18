##
## EPITECH PROJECT, 2023
## printf
## File description:
## Makefile
##

SRC	=	./src/my_printf.c	\
		./src/character.c	\
		./src/string.c		\
		./src/integer.c

TESTS = ./src/tests/tests_printf.c

OBJ = $(SRC:.c=.o)

OBJ_TESTS = $(TESTS:.c=.o)

LIB = ./lib

INCLUDE = ./include

NAME = $(LIB)/libprintf.a

CFLAGS = -I$(INCLUDE) -Wall -Wextra -Werror


all: tests

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

unit_tests: $(NAME) $(OBJ_TESTS)
	gcc -o unit_tests  $(OBJ_TESTS) -L$(LIB) -lprintf -I$(INCLUDE) -lcriterion

tests: unit_tests
	./unit_tests

clean:
	rm -f $(OBJ) $(OBJ_TESTS)

fclean: clean
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re tests all