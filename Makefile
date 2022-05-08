##
## EPITECH PROJECT, 2021
## B-CPE-110-BDX-1-1-BSQ-leandre.godet
## File description:
## Makefile
##
CFLAGS = -Wall -Wextra -Wshadow
CPPFLAGS = -I ./include

SRC = 	src/main.c \
		src/command.c \
		src/my_shell.c \
		src/env_copy.c \
		src/shell_echo.c \
		src/shell_loop.c \
		src/path_array.c \
		src/check_stdin.c \
		src/find_binary.c \
		src/builtin/my_cd.c \
		src/builtin/my_env.c \
		src/builtin/my_exit.c \
		src/builtin/my_setenv.c \
		src/builtin/change_dir.c \
		src/builtin/my_unsetenv.c \

OBJ = $(SRC:.c=.o)

NAME = mysh

LIB = lib/my/libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my/
		make fclean -C tests

tests_run:
		make re -C tests
		./unit_tests
		gcovr

re: fclean all

.PHONY: clean $(NAME) all fclean
