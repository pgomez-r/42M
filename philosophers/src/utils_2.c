/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:09:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/09 21:56:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*Recoge el tiempo actual en milisegundos*/
u_int64_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

/*Mejora de usleep para que sea más fiable*/
int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	ft_free_env(t_env *d)
{
	if (d->philos)
		free (d->philos);
	if (d->forks)
		free (d->forks);
	if (d->fork_mutex)
		free (d->fork_mutex);
}

void	ft_log(t_ph *ph, char *msg)
{
	u_int64_t	time;

	pthread_mutex_lock(&ph->d->print);
	time = ph->d->start_time - (ft_get_time());
	printf("[%llu]--philo[%d]--%s\n", time, ph->num, msg);
	pthread_mutex_unlock(&ph->d->print);
}

void	ft_destroy_mutex(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
		pthread_mutex_destroy(&d->fork_mutex[i]);
}
