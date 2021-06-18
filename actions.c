/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:20:14 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/18 16:11:10 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->print_mutex);
	// if (phil->all->finish_flag == 0)
	printf("%d ms Ph#%d is thinking\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);
}

void	eating(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->print_mutex);
	phil->t = get_cur_time(phil->all->start);
	// if (phil->all->finish_flag == 0)
	printf("%d ms Ph#%d is eating\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);

	while (get_cur_time(phil->all->start) - phil->t < phil->all->eat_time)
		usleep(1);
	return ;
}

void	sleeping(t_philosopher *phil)
{
	int s;
	
	pthread_mutex_lock(&phil->all->print_mutex);
	s = get_cur_time(phil->all->start);
	// if (phil->all->finish_flag == 0)
	printf("%d ms Ph#%d is sleeping\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);

	while (get_cur_time(phil->all->start) - s < phil->all->sleep_time)
		usleep(1);
	return ;
}

int	check_phs_hearts(t_philosopher *ph)
{
	pthread_mutex_lock(&ph->all->print_mutex);

	int i;

	i = -1;
	while (++i < ph->all->num_of_phs)
	{
		if (get_cur_time(ph->all->start) - ph[i].t >= ph->all->die_time)
		{
			// ph->all->finish_flag = 1;
			printf("%d ms Ph#%d died\n", get_cur_time(ph->all->start), ph[i].num);
			return (0);
		}
	}
	pthread_mutex_unlock(&ph->all->print_mutex);
	return (1);
}