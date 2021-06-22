/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:59:12 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/22 13:10:37 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_traces(t_philosopher *ph)
{
	int i;
	

	//all pthread detach
	i = -1;
	while (++i < ph->all->num_of_phs)
		if (pthread_detach(ph[i].thr) != SUCCESS)
			error_found("Pthread detach error");

	//all mutex_unlock
	i = -1;
	while (++i < ph->all->num_of_phs)
		if (ph->all->forks[i].fl == 1)
			unlock_mutex(&ph->all->forks[i]);

	//all mutex destroy
	i = -1;
	while (++i < ph->all->num_of_phs)
		pthread_mutex_destroy(&ph->all->forks[i].fork);
		// if (pthread_mutex_destroy(&ph->all->forks[i].fork) == EBUSY)
		// 	error_found("Mutex destroy error!");
	

	//unlock and destroy print mutex
	if (pthread_mutex_unlock(&ph->all->print_mutex) != SUCCESS)
		error_found("Print mutex unlock error");
	pthread_mutex_destroy(&ph->all->print_mutex);
	// if (pthread_mutex_destroy(&ph->all->print_mutex) == EBUSY)
	// 	error_found("Mutex destroy error!!!");
	free(ph->all->forks);
	free(ph);

	return (0);
}


void	error_found(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

void	*ft_memset(void *dest, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)dest;
	while (i < (int)n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

int	ft_memfree(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

char	*mall(char **str, int n)
{
	*str = malloc(sizeof(char) * n);
	if (*str == NULL)
		return (NULL);
	else
		return (*str);
}
