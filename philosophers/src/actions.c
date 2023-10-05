/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:26:58 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/05 15:28:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	pick_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 1;
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 1;
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
	}
}

void	drop_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 0;
	}
	else
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 0;
	}
}

void	philo_eat(t_ph	*ph)
{
	ph->fed_time = get_time();
	printf("Philo %d is eating.\n");
	ft_usleep(ph->d->time_eat);
}

void	philo_sleep(t_ph *ph)
{
	printf("Philo %d is sleeping.\n");
	ft_usleep(ph->d->time_sleep);
}
