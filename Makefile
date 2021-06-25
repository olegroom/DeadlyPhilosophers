SRC = src/actions.c     src/help1.c      src/memory.c     src/parser.c    src/philo_main.c src/death.c

HEADER = philo.h

NAME = philo

all: $(SRC)
	gcc $(SRC) -g -Wall -Wextra -Werror -o $(NAME)
	./$(NAME) 181 130 60 60 

clean:

fclean: clean
	rm a.out