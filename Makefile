SRC = actions.c help1.c      memory.c     parser.c     philo.h      philo_main.c

NAME = philo

all: $(SRC)
	gcc $(SRC) -g
	./a.out 3 2500 2000 1000 5

without_noe: 
	gcc $(SRC) -g
	./a.out 3 8445 3453 3767

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