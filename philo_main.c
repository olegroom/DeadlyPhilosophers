/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:39:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/15 19:47:11 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_to_live(void *args)
{
	t_philo *all = (t_philo *)args;
	while(1)
	{
		// thinking(all);
		// eating(all);
		sleeping(all);
	}
	return (NULL);
}

void	ft_run_threads(t_philo *all)
{
	int i;

	i = -1;
	while (++i < all->num_of_phs)
	{
		if (pthread_create(&all->thr[i], NULL, ft_start_to_live, all) != SUCCESS)
			error_found("Creation thread error");
		all->philos[i].num = i;
		all->philos[i].num_of_eats = 0;
		all->philos[i].thr_ID = (int)all->thr[i];
		// printf("Philosopher #%d Have %d ID\n", all->philos[i].num, all->philos[i].thr_ID);
		usleep(1000);
	}

	while(all->finish_flag == 0)
		continue;
}

int	main(int ac, char **argv)
{
	t_philo	all;

	if (pthread_mutex_init(&all.mutex, NULL) != SUCCESS)
		error_found("Mutex init error");
	gettimeofday(&all.start, NULL);
	if (ac != 6 && ac != 5)
		error_found("Wrong number of arguments");
	ft_pars_and_init(&all, argv);
	show_data(&all);
	
	
	ft_run_threads(&all);

	get_cur_time(all.start);
	pthread_mutex_destroy(&all.mutex);
	return (0);
}
