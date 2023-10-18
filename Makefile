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

TESTS = ./src/tests/tests_printf.c \
		./src/tests/tests_lib_c_printf.c

OBJ = $(SRC:.c=.o)

OBJ_TESTS = $(TESTS:.c=.o)

LIB = ./lib

INCLUDE = ./include

NAME = $(LIB)/libprintf.a

ARFLAGS	=	rc

CC	=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)
CFLAGS = -Wall -Wextra -Werror
LDFLAGS	=
LDLIBS	=

all: tests

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

unit_tests: CFLAGS += -fprofile-arcs -ftest-coverage
unit_tests: LDFLAGS	+= -lcriterion -lgcov
unit_tests: $(OBJ) $(OBJ_TESTS)
	$(CC) -o unit_tests $(OBJ) $(OBJ_TESTS) $(LDLIBS) $(LDFLAGS)

tests: unit_tests
	./unit_tests

clean:
	$(RM) $(OBJ) $(OBJ_TESTS)

fclean: clean
	$(RM) unit_tests
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re tests all
