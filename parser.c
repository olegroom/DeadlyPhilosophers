/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:01:21 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/22 12:34:10 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//add pars "only digits" in ft_atoi*.c

#include "philo.h"

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
		error_found("Please, delete any signs in the start of input digits");
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			error_found("Wrong input. Need to be only digits");
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num > 2147483647)
		error_found("Too big input value");
	return (num);
}

void	ft_pars_and_init(t_philo *all, char **argv)
{
	int i;

	all->i = 0;
	all->finish_flag = 0;
	all->num_of_phs = ft_atoi(argv[1]);
	all->forks = malloc(sizeof(t_mutex) * all->num_of_phs);

	i = -1;
	while (++i < all->num_of_phs)
	{
		if (pthread_mutex_init(&all->forks[i].fork, NULL) != SUCCESS)
			error_found("Mutex init error");
		all->forks[i].fl = 0;
	}
	all->die_time = ft_atoi(argv[2]);
	all->eat_time = ft_atoi(argv[3]);
	all->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		all->nums_of_eatings = ft_atoi(argv[5]);
		all->fl_noe = 1;
	}
	else
		all->fl_noe = 0;
}
