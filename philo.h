#ifndef PHILO_H
# define PHILO_H
# define SUCCESS 0

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>

typedef struct	s_mutex
{
	pthread_mutex_t fork;
	int fl;
}				t_mutex;

typedef struct  s_philo
{
    int num_of_phs;
    int die_time;
    int eat_time;
    int sleep_time;
    int nums_of_eatings;
    struct timeval start;
    int fl_noe;
	int i;
	int finish_flag;
	pthread_mutex_t print_mutex;
	pthread_mutex_t to_lock_mutex;
	t_mutex *forks;
}               t_philo;

typedef struct	s_philosopher
{
	int num_eats;
	int t;
	int num;
	int fl;
	t_philo *all;
	pthread_t thr;
}				t_philosopher;

int		clear_traces(t_philosopher *ph);
int		take_forks(t_philosopher *phil);
void	unlock_mutex(t_mutex *forks);
void	lock_mutex(t_mutex *forks);
void	print_cur_time(struct timeval start);
void	show_data(t_philo *all);
int     get_cur_time(struct timeval start);
void    ft_pars_and_init(t_philo *all, char **argv);
int     len(long int nbr);
int     ft_atoi(const char *str);
void    *ft_memset(void *dest, int c, size_t n);
int     ft_memfree(char **str);
char    *mall(char **str, int n);
void	error_found(char *str);
void	eating(t_philosopher *phil);
void	sleeping(t_philosopher *phil);
void	thinking(t_philosopher *phil);
int		check_phs_hearts(t_philosopher *ph);
int		check_number_of_eats(t_philosopher *ph);
#endif