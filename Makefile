SRC = src/actions.c     src/help1.c      src/memory.c     src/parser.c    src/philo_main.c src/death.c

HEADER = philo.h

NAME = philo

O_FLAGS = -O2

all: $(SRC)
	gcc $(SRC) -g -Wall -Wextra -Werror -o $(NAME)
	./$(NAME) 4 130 60 60

clean:

fclean: clean
	rm a.out