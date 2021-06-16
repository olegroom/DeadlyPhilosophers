/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:20:14 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/15 19:47:25 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void thinking(t_philo *all)
{
	
}

void eating(t_philo *all)
{
	printf("Ph is eating\n");
}

void sleeping(t_philo *all)
{
	get_cur_time(all->start);
	printf("is sleeping\n");
	usleep(all->sleep_time * 1000);
}
