/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:43:02 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/20 11:11:07 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char const *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	long int	sig;
	long int	num;

	sig = 1;
	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	if (ft_isdigit((int) *str) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{	
		num = (*str - '0') + (num * 10);
		str++;
	}
	return (num * sig);
}

void	update_stat(int *stat, t_env *d)
{
	pthread_mutex_lock(&d->finish_mtx);
	(*stat) = d->finish;
	pthread_mutex_unlock(&d->finish_mtx);
}
