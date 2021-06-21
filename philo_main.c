/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:39:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/21 20:24:34 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*ft_start_to_live(void *args)
{
	t_philosopher	*phil;
	
	phil = (t_philosopher *)args;

	while(1)
	{
		thinking(phil);
		take_forks(phil);
		// eating(phil);
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

	usleep(1000);
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
	
	
	int i = -1;
	
	while (++i < all.num_of_phs)
	{
		if (pthread_mutex_destroy(&all.forks[i].fork) != SUCCESS)
			error_found("Mutex destroy error");
	}
	pthread_mutex_destroy(&all.print_mutex);
	return (0);
}
