/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:26:58 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/20 11:22:18 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	pick_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 1;
		ft_log(ph, "has taken a fork", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		ft_log(ph, "has taken a fork", YELLOW);
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 1;
		ft_log(ph, "has taken a fork", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		ft_log(ph, "has taken a fork", YELLOW);
	}
}

void	drop_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		ph->d->forks[ph->d->num_ph - 1] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->num - 1] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
	}
	else
	{
		ph->d->forks[ph->num - 2] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 1] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
	}
}

void	philo_eat(t_ph	*ph)
{
	ft_log(ph, "is eating", GREEN);
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	ph->round++;
	if (ph->round == ph->d->rounds)
	{	
		pthread_mutex_lock(&ph->full_mtx);
		ph->full = 1;
		pthread_mutex_unlock(&ph->full_mtx);
	}
	while (1)
	{
		pthread_mutex_lock(&ph->time_mtx);
		if ((ft_get_time() - ph->fed_time) >= ph->d->time_eat)
		{
			pthread_mutex_unlock(&ph->time_mtx);
			return ;
		}
		pthread_mutex_unlock(&ph->time_mtx);
	}
}

void	philo_sleep(t_ph *ph)
{
	time_t	now;

	ft_log(ph, "is sleeping", CYN);
	now = ft_get_time();
	while (1)
	{
		if ((ft_get_time() - now) >= ph->d->time_sleep)
			return ;
	}
}

void	ft_monitor(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		if (check_ko(d, &d->philos[i]) == 1)
		{	
			pthread_mutex_lock(&d->finish_mtx);
			d->finish = 1;
			pthread_mutex_unlock(&d->finish_mtx);
			return ;
		}
	}
	if (check_meals(d))
	{
		pthread_mutex_lock(&d->finish_mtx);
		d->finish = 2;
		pthread_mutex_unlock(&d->finish_mtx);
		return ;
	}
}
