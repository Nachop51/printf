CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format
SRC=*.c
NAME=printf
RM=rm -f

all: compile run remove

remove:
	$(RM) $(NAME)

run:
	./$(NAME)

compile:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
