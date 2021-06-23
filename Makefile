SRC = src/actions.c     src/help1.c      src/memory.c     src/parser.c    src/philo_main.c src/death.c

HEADER = philo.h

NAME = philo

O_FLAGS = -O2

all: $(SRC)
	gcc $(SRC) -g -Wall -Wextra -Werror -o $(NAME)
	./$(NAME) 2 100 1500 300

die:
	gcc $(SRC) -g
	./a.out 3 20 2000 1000 5

crash1:
	gcc $(SRC)
	./a.out 10 8445 2453 2766 34534 534

crash2:
	gcc $(SRC)
	./a.out 10 sdf 2453 saa

crash3:
	gcc $(SRC)
	./a.out 10 8445 2453sdf 2766 4

negative:
	gcc $(SRC)
	./a.out 10 8445 -2453 2766 3

clean:

fclean: clean
	rm a.out