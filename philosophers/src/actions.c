/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:26:58 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/12 20:50:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	pick_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		ft_log(ph, "has taken a fork.", YELLOW);
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
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	ft_log(ph, "is eating.", GREEN);
	pthread_mutex_lock(&ph->round_mtx);
	ph->round++;
	pthread_mutex_unlock(&ph->round_mtx);
	ft_usleep(ph->d->time_eat);
}

void	philo_sleep(t_ph *ph)
{
	ft_log(ph, "is sleeping.", CYN);
	ft_usleep(ph->d->time_sleep);
}
