/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:43:02 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/16 21:31:17 by pgomez-r         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int		sig;
	int		num;

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

void	first_pick(t_ph *ph)
{
	if (ph->d->forks[ph->d->num_ph - 1] == 0)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	if (ph->d->forks[ph->num - 1] == 0)
	{	
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	ph->stat = 1;
}

void	first_drop(t_ph *ph)
{
	if (ph->d->forks[ph->d->num_ph - 1] == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 0;
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	if (ph->d->forks[ph->num - 1] == 1)
	{	
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 0;
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	philo_sleep(ph);
	ft_log(ph, "is thinking.", MAG);
	ph->stat = 0;
}