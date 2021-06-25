/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:02:26 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/25 14:29:13 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	intlen(int d)
{
	int i;

	i = 0;
	while (d > 0)
	{
		d /= 10;
		i++;		
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000000 + end.tv_usec) - \
	(start.tv_sec * 1000000 + start.tv_usec)) / 1000;
}
