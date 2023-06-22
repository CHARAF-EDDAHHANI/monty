CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 # -g

SRC=main.c instructions_1.c instructions_2.c instructions_3.c auxiliary_1.c auxiliary_2.c
INC=monty.h

NAME=monty

all: $(NAME) $(INC)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)


clean:
	@rm -f $(NAME)

re: clean all
