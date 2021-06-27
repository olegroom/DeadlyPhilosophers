/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:01:21 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/27 18:41:53 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int 	len(long int nbr)
{
	int	l;

	l = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		l++;
	}
	return (l);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;

	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num > 2147483647)
		return (-1);
	return (num);
}

int	mutex_creation(t_philo *all)
{
	int	i;

	i = -1;
	while (++i < all->num_of_phs)
		if (pthread_mutex_init(&all->forks[i], NULL) != SUCCESS)
			return (error_found("Mutex init error"));
	if (pthread_mutex_init(&all->print_mutex, NULL))
		return (error_found("Mutex init error"));
	if (pthread_mutex_init(&all->to_lock_mutex, NULL))
		return (error_found("Mutex init error"));
	return (0);
}

int	ft_pars_and_init(t_philo *all, char **argv)
{
	all->num_of_phs = ft_atoi(argv[1]);
	all->forks = malloc(sizeof(pthread_mutex_t) * all->num_of_phs);
	if (all->forks == NULL)
		error_found("Malloc error");
	if (mutex_creation(all) == -1)
		return (-1);
	all->finish_flag = 0;
	all->die_time = ft_atoi(argv[2]);
	all->eat_time = ft_atoi(argv[3]);
	all->sleep_time = ft_atoi(argv[4]);
	if (all->num_of_phs == -1 || all->die_time == -1 || \
	all->eat_time == -1 || all->sleep_time == -1)
		return (-1);
	if (argv[5])
	{
		all->nums_of_eatings = ft_atoi(argv[5]);
		if (all->nums_of_eatings == -1)
			return (-1);
		all->fl_noe = 1;
	}
	else
		all->fl_noe = 0;
	return (0);
}
