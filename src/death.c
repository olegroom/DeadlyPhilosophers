/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:56:30 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/23 17:37:22 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_phs_hearts(t_philosopher *ph)
{
	pthread_mutex_lock(&ph->all->print_mutex);
	int i;

	i = -1;
	while (++i < ph->all->num_of_phs)
	{
		if (get_cur_time(ph->all->start) - ph[i].t >= ph->all->die_time)
		{
			ph->all->finish_flag = 1;
			printf("%d ms Ph#%d died\n", get_cur_time(ph->all->start), ph[i].num);
			return (1);
		}
	}
	pthread_mutex_unlock(&ph->all->print_mutex);
	return (0);
}

int	check_number_of_eats(t_philosopher *ph)
{
	int i;

	i = -1;
	while (++i < ph->all->num_of_phs)
	{
		if (ph[i].num_eats >= ph->all->nums_of_eatings)
			continue ;
		return (0);
	}
	return (1);
}
