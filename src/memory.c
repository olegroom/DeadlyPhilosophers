/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:59:12 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/25 14:27:08 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	clear_traces(t_philosopher *ph)
{
	exit(0);
	int i;
	
	i = -1;
	while (++i < ph->all->num_of_phs)
		pthread_mutex_unlock(&ph->all->forks[i]);
	usleep(100);
	i = -1;
	while (++i < ph->all->num_of_phs)
		pthread_mutex_destroy(&ph->all->forks[i]);
		// if (pthread_mutex_destroy(&ph->all->forks[i]) == EBUSY)
		// 	return(error_found("Mutex destroy error!"));
	i = -1;
	while (++i < ph->all->num_of_phs)
		if (pthread_detach(ph[i].thr) != SUCCESS)
			return(error_found("Pthread detach error"));
	
	//unlock and destroy print mutex (+ to_lock_mutex)
	// pthread_mutex_unlock(&ph->all->to_lock_mutex);
	// pthread_mutex_destroy(&ph->all->to_lock_mutex);
	if (pthread_mutex_unlock(&ph->all->print_mutex) != SUCCESS)
		return(error_found("Print mutex unlock error"));
	usleep(100);
	if (pthread_mutex_destroy(&ph->all->print_mutex) == EBUSY)
		return(error_found("Mutex destroy error!!!"));
	// pthread_mutex_destroy(&ph->all->print_mutex);

	return (0);
}


int	error_found(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
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
