/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:39:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/18 16:08:35 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_to_live(void *args)
{
	t_philosopher	*phil;
	
	phil = (t_philosopher *)args;
	while (phil->checker == 1)
		continue ;

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
	while (++i < all->num_of_phs + 1)
	{
		if (i == all->num_of_phs)
			ph[i].checker = 1;
		else
			ph[i].checker = 0;
		ph[i].all = all;
		ph[i].num = i;
		if (pthread_mutex_init(&ph[i].right_fork, NULL) != SUCCESS)
			error_found("Mutex init error");
		if (i + 1 == all->num_of_phs)
			ph[0].left_fork = ph[i].right_fork;
		else if (i < all->num_of_phs)
			ph[i + 1].left_fork = ph[i].right_fork;
		if (pthread_create(&ph[i].thr, NULL, ft_start_to_live, &ph[i]) != SUCCESS)
			error_found("Creation thread error");
	}

	while(check_phs_hearts(ph) == 1)
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
