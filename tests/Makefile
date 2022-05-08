##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	test_builtin.c \
		../src/command.c \
		../src/my_shell.c \
		../src/env_copy.c \
		../src/shell_loop.c \
		../src/path_array.c \
		../src/shell_echo.c \
		../src/find_binary.c \
		../src/check_stdin.c \
		../src/builtin/my_cd.c \
		../src/builtin/my_env.c \
		../src/builtin/my_exit.c \
		../src/builtin/my_setenv.c \
		../src/builtin/change_dir.c \
		../src/builtin/my_unsetenv.c \

NAME =	unit_tests

OBJ = $(SRC.c=.o)

CFLAGS = -I ../include
CPPFLAGS = --coverage -lcriterion

LIB = ../lib/my/libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LIB)
	cp unit_tests ../

clean:
	rm -f $(NAME)
	rm -f ../$(NAME)

fclean:	clean
	rm -f *~
	rm -f *.gc*

re:	fclean all

.PHONY: all clean fclean re
