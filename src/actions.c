/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:20:14 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/24 15:06:17 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	thinking(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->print_mutex);
	if (phil->all->finish_flag == 0)
		printf("%d ms Ph#%d is thinking\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);
}

void	take_forks(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->to_lock_mutex);
	pthread_mutex_lock(phil->le_f);
	if (phil->all->finish_flag == 0)
		printf("%d ms Ph#%d has taken a fork\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_lock(phil->ri_f);
	if (phil->all->finish_flag == 0)
		printf("%d ms Ph#%d has taken a fork\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->to_lock_mutex);
}

void	eating(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->all->print_mutex);
	if (phil->all->finish_flag == 0)
		printf("%d ms Ph#%d is eating\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);
	if (phil->all->fl_noe == 1)
		phil->num_eats++;
	phil->t = get_cur_time(phil->all->start);
	while ((get_cur_time(phil->all->start) - phil->t) < phil->all->eat_time)
		usleep(1000);
}

void	drop_forks(t_philosopher *phil)
{
	pthread_mutex_unlock(phil->le_f);
	pthread_mutex_unlock(phil->ri_f);
}

void	sleeping(t_philosopher *phil)
{
	int s;
	
	pthread_mutex_lock(&phil->all->print_mutex);
	if (phil->all->finish_flag == 0)
		printf("%d ms Ph#%d is sleeping\n", get_cur_time(phil->all->start), phil->num);
	pthread_mutex_unlock(&phil->all->print_mutex);

	s = get_cur_time(phil->all->start);
	while ((get_cur_time(phil->all->start) - s) < phil->all->sleep_time)
		usleep(1000);
}
