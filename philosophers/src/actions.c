/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:26:58 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/13 16:49:44 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	pick_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
	}
}

void	drop_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ft_log(ph, "has left a fork.", YELLOW);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has left a fork.", YELLOW);
	}
	else
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 2]);
		ft_log(ph, "has left a fork.", YELLOW);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has left a fork.", YELLOW);
	}
}

/*El fed_time cuando empieza a comer o cuando termina? =/*/

void	philo_eat(t_ph	*ph)
{
	ft_log(ph, "is eating.", GREEN);
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	//ft_usleep(ph->d->time_eat);
	while (1)
	{
		pthread_mutex_lock(&ph->time_mtx);
		if ((ft_get_time() - ph->fed_time) >= ph->d->time_eat)
		{
			pthread_mutex_unlock(&ph->time_mtx);
			pthread_mutex_lock(&ph->round_mtx);
			ph->round++;
			pthread_mutex_unlock(&ph->round_mtx);
			return ;
		}
		pthread_mutex_unlock(&ph->time_mtx);
	}
}

void	philo_sleep(t_ph *ph)
{
	time_t	now;

	ft_log(ph, "is sleeping.", CYN);
	//ft_usleep(ph->d->time_sleep);
	now = ft_get_time();
	while (1)
	{
		if ((ft_get_time() - now) >= ph->d->time_sleep)
		{
			pthread_mutex_lock(&ph->round_mtx);
			ph->round++;
			pthread_mutex_unlock(&ph->round_mtx);
			return ;
		}
	}
}
