/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:59:12 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/27 18:23:17 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	clear_traces(t_philosopher *ph)
{
	int	i;

	i = -1;
	while (++i < ph->all->num_of_phs)
		pthread_mutex_unlock(&ph->all->forks[i]);
	i = -1;
	while (++i < ph->all->num_of_phs)
		pthread_mutex_destroy(&ph->all->forks[i]);
	i = -1;
	while (++i < ph->all->num_of_phs)
		if (pthread_detach(ph[i].thr) != SUCCESS)
			return (error_found("Pthread detach error\n"));
	if (pthread_mutex_unlock(&ph->all->print_mutex) != SUCCESS)
		return (error_found("Print mutex unlock error\n"));
	usleep(100);
	if (pthread_mutex_destroy(&ph->all->print_mutex) == EBUSY)
		return (error_found("Mutex destroy error!!!\n"));
	pthread_mutex_destroy(&ph->all->print_mutex);
	return (0);
}

int	error_found(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
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
	*str = malloc(n);
	if (*str == NULL)
		return (NULL);
	else
		return (*str);
}
