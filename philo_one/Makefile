SRC = src/actions.c     src/help1.c      src/memory.c     src/parser.c    src/philo_main.c src/death.c

HEADER = philo.h

NAME = philo_one

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $(NAME)

all: $(SRC)
	gcc $(SRC) -g -Wall -Wextra -Werror -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(NAME).dSYM
	rm -f ./srcs/.DS_Store

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY = all clean fclean re
