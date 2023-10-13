/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:09:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/13 16:19:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*Recoge el tiempo actual en milisegundos*/
time_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*Mejora de usleep para que sea más fiable*/
int	ft_usleep(time_t time)
{
	time_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(10);
	return (0);
}

void	ft_log(t_ph *ph, char *msg, char *color)
{
	time_t	time;

	pthread_mutex_lock(&ph->d->print);
	time = ft_get_time() - ph->d->start_time;
	pthread_mutex_lock(&ph->d->finish_mtx);
	if (ph->d->finish == 0)
		printf("%s[%ld]--philo[%d]--%s\n\033[0m", color, time, ph->num, msg);
	pthread_mutex_unlock(&ph->d->finish_mtx);
	pthread_mutex_unlock(&ph->d->print);
}

int	check_ko(t_env *d, t_ph *ph)
{
	time_t	time;

	time = ft_get_time();
	pthread_mutex_lock(&ph->time_mtx);
	if ((time - ph->fed_time) >= d->time_die)
	{
		ft_log(ph, "had died.", RED);
		return (pthread_mutex_unlock(&ph->time_mtx), 1);
	}
	return (pthread_mutex_unlock(&ph->time_mtx), 0);
}
