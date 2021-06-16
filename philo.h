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


typedef struct	s_philosopher
{
	int num;
	int thr_ID;
	int num_of_eats;
}				t_philosopher;

typedef struct  s_philo
{
    int num_of_phs;
    int num_of_forks;
    int die_time;
    int eat_time;
    int sleep_time;
    int nums_of_eatings;
    int *phs;
    struct timeval start;
    int cur_time_mls;
    int fl_noe;
	int i;
	int finish_flag;
	pthread_mutex_t mutex;
	pthread_t *thr;
	t_philosopher *philos;
}               t_philo;

void	show_data(t_philo *all);
void	print_while(char *str);
int     get_cur_time(struct timeval start);
void    ft_pars_and_init(t_philo *all, char **argv);
double	ft_atoi_double(const char *str);
int     len(long int nbr);
int     ft_atoi(const char *str);
void    *ft_memset(void *dest, int c, size_t n);
int     ft_memfree(char **str);
char    *mall(char **str, int n);
void	error_found(char *str);
void	eating(t_philo *all);
void	sleeping(t_philo *all);
void	thinking(t_philo *all);

#endif