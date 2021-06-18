/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:39:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/18 19:52:20 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_to_live(void *args)
{
	t_philosopher	*phil;
	
	phil = (t_philosopher *)args;

	// if (pthread_mutex_init(&phil[phil->num].right_fork, NULL) != SUCCESS)
	// 	error_found("Mutex init error");
	// if (i + 1 == all->num_of_phs)
	// 	ph[0].left_fork = ph[i].right_fork;
	// phil[phil->num + 1].left_fork = phil[phil->num].right_fork;

	// if (phil->num == 0) {
	// 	printf("%p\n", &phil[phil->num].left_fork);
	// 	printf("%p\n", &phil[phil->num].right_fork);
	// }
	// if (phil->num == 1) {
	// 	printf("%p\n", &phil[phil->num].left_fork);
	// 	printf("%p\n", &phil[phil->num].right_fork);
	// }
	// if (phil->num == 2) {
	// 	printf("%p\n", &phil[phil->num].left_fork);
	// 	printf("%p\n", &phil[phil->num].right_fork);
	// }
		

	while(1)
	{
		thinking(phil);
		eating(phil);
		sleeping(phil);
	}
	return (NULL);
}

void	ft_run_threads(t_philo *all)
{
	t_philosopher *ph;
	int i;

	ph = malloc(sizeof(t_philosopher) * all->num_of_phs + 1);
	i = -1;
	while (++i < all->num_of_phs)
	{
		ph[i].all = all;
		ph[i].num = i;
		ph[i].num_eats = 0;
		if (pthread_create(&ph[i].thr, NULL, ft_start_to_live, &ph[i]) != SUCCESS)
			error_found("Creation thread error");
	}

	if (ph->all->fl_noe == 0)
		while (check_phs_hearts(ph) == 0)
			continue ;
	else if (ph->all->fl_noe == 1)
		while(check_phs_hearts(ph) == 0 && check_number_of_eats(ph) == 0)
			continue ;
	
	i = -1;
	while (++i < ph->all->num_of_phs + 1)
		pthread_detach(ph[i].thr);
	free(ph);
}

int	main(int ac, char **argv)
{
	t_philo	all;

	gettimeofday(&all.start, NULL);
	if (ac != 6 && ac != 5)
		error_found("Wrong number of arguments");
	ft_pars_and_init(&all, argv);
	show_data(&all);

	if (pthread_mutex_init(&all.print_mutex, NULL) != SUCCESS)
		error_found("Mutex init error");
	
	ft_run_threads(&all);
	
	pthread_mutex_destroy(&all.print_mutex);
	return (0);
}
