/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:59:12 by rosfryd           #+#    #+#             */
/*   Updated: 2021/06/21 16:42:50 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *str)
{
	//probably add some free functions
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
