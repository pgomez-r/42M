/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:06:58 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/17 22:30:45 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_env_struct(t_env *d)
{
	d->start_time = 0;
	d->finish = 0;
	d->ko = 0;
	pthread_mutex_init(&d->print, NULL);
	pthread_mutex_init(&d->finish_mtx, NULL);
	pthread_mutex_init(&d->ko_mtx, NULL);
}

void	gen_philos(t_env *d)
{
	int	i;

	d->start_time = ft_get_time();
	i = -1;
	while (++i < d->num_ph)
	{
		d->philos[i].num = i + 1;
		d->philos[i].full = 0;
		d->philos[i].round = 0;
		d->philos[i].d = d;
		pthread_mutex_init(&d->philos[i].time_mtx, NULL);
		pthread_mutex_init(&d->philos[i].full_mtx, NULL);
		pthread_mutex_lock(&d->philos[i].time_mtx);
		d->philos[i].fed_time = d->start_time;
		pthread_mutex_unlock(&d->philos[i].time_mtx);
		if (d->num_ph == 1)
		{		
			pthread_create(&d->philos[i].tid, NULL, &one_philo, &d->philos[i]);
			return ;
		}
		pthread_create(&d->philos[i].tid, NULL, &routine, &d->philos[i]);
	}
}

t_env	parse_params(char **av)
{
	t_env	d;
	int		i;

	d.num_ph = ft_atoi(av[1]);
	d.philos = malloc(sizeof(t_ph) * d.num_ph);
	d.forks = malloc(sizeof(int) * d.num_ph);
	d.fork_mutex = malloc(sizeof(pthread_mutex_t) * d.num_ph);
	i = -1;
	while (++i < d.num_ph)
	{	
		d.forks[i] = 0;
		pthread_mutex_init(&d.fork_mutex[i], NULL);
	}
	d.time_die = ft_atoi(av[2]);
	d.time_eat = ft_atoi(av[3]);
	d.time_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		d.rounds = ft_atoi(av[5]);
	else
		d.rounds = -1;
	init_env_struct(&d);
	return (d);
}

int	ft_args_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
