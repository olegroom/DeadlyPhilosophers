/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:02:26 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/21 20:57:14 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_mutex(t_mutex *forks)
{
	if (pthread_mutex_unlock(&forks->fork) != SUCCESS)
		error_found("Unlock mutex error");
	forks->fl = 0;
}

void	lock_mutex(t_mutex *forks)
{
	if (pthread_mutex_lock(&forks->fork) != SUCCESS)
		error_found("Lock mutex error");
	forks->fl = 1;
}

void	show_data(t_philo *all)
{
	printf("\nNumber of phs = %d\n", all->num_of_phs);
	printf("Time to die(without eating) = %d\n", all->die_time);
	printf("Time ph need to eat = %d\n", all->eat_time);
	printf("Time ph need to sleep = %d\n\n", all->sleep_time);
	if (all->fl_noe)
		printf("Number of eatings (for each ph) = %d\n\n", all->nums_of_eatings);
}

int	get_cur_time(struct timeval start)
{
	struct timeval	end;
	int				c_t;

	gettimeofday(&end, NULL);
	c_t = ((end.tv_sec * 1000000 + end.tv_usec) - \
	(start.tv_sec * 1000000 + start.tv_usec)) / 1000;
	return (c_t);
}
