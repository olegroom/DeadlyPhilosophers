/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:39:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/27 17:07:03 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_start_to_live(void *args)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)args;
	while (1)
	{
		thinking(phil);
		take_forks(phil);
		eating(phil);
		drop_forks(phil);
		sleeping(phil);
	}
	return (NULL);
}

void	run_threads(t_philo *all, t_philosopher *ph)
{
	int	i;

	i = -1;
	while (++i < all->num_of_phs)
	{
		if (i == 0)
			ph[i].le_f = &all->forks[all->num_of_phs - 1];
		else
			ph[i].le_f = &all->forks[i - 1];
		ph[i].ri_f = &all->forks[i];
		ph[i].all = all;
		ph[i].num = i;
		ph[i].num_eats = 0;
	}
	i = -1;
	while (++i < all->num_of_phs)
	{
		pthread_create(&ph[i].thr, NULL, ft_start_to_live, &ph[i]);
		usleep(20);
	}
}

void	checking_if_program_should_exit(t_philosopher *ph)
{
	if (ph->all->fl_noe == 0)
		while (check_phs_hearts(ph) == 0)
			usleep(1000);
	else
		while (check_phs_hearts(ph) == 0 && check_number_of_eats(ph) == 0)
			usleep(1000);
}

int	launching_the_program(t_philo *all)
{
	t_philosopher	*ph;

	ph = malloc(sizeof(t_philosopher) * all->num_of_phs + 1);
	run_threads(all, ph);
	usleep(20 * all->num_of_phs + 1000);
	checking_if_program_should_exit(ph);
	return (clear_traces(ph));
}

int	main(int ac, char **argv)
{
	t_philo	all;

	gettimeofday(&all.start, NULL);
	if (ac != 6 && ac != 5)
		return (error_found("Wrong number of arguments\n"));
	if (ft_pars_and_init(&all, argv) == -1)
		return (error_found("Input data format error\n"));
	return (launching_the_program(&all));
}
