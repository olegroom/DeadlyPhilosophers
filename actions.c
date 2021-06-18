/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:20:14 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/17 22:50:26 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->print_mutex);
	printf("%d ms Ph#%d is thinking\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);
}

void	eating(t_philosopher *phil)
{
	phil->t = get_cur_time(phil->all->start);

	pthread_mutex_lock(&phil->all->print_mutex);
	printf("%d ms Ph#%d is eating\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);

	phil->num_of_eats++;
	while (get_cur_time(phil->all->start) - phil->t < phil->all->eat_time)
		usleep(1);
	return ;
}

void	sleeping(t_philosopher *phil)
{
	int s;

	pthread_mutex_lock(&phil->all->print_mutex);
	printf("%d ms Ph#%d is sleeping\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);

	s = get_cur_time(phil->all->start);
	while (get_cur_time(phil->all->start) - s < phil->all->sleep_time)
		usleep(1);
	return ;
}

void	death_declare(t_philosopher *ph, int i)
{
	pthread_mutex_lock(&ph->all->print_mutex);
	printf("%d ms Ph#%d died\n", get_cur_time(ph->all->start), ph[i].num);
	pthread_mutex_unlock(&ph->all->print_mutex);
	i = -1;
	while (++i < ph->all->num_of_phs + 1)
		pthread_detach(ph[i].thr);
	pthread_mutex_unlock(&ph->all->print_mutex);
}

int	check_phs_hearts(t_philosopher *ph)
{
	int i;

	i = -1;
	while (++i < ph->all->num_of_phs)
		if (get_cur_time(ph->all->start) - ph[i].t >= ph->all->die_time)
		{
			death_declare(ph, i);
			return (0);
		}
	return (1);
}