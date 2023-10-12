/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:06:58 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/12 20:40:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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
	d.start_time = 0;
	d.finish = 0;
	pthread_mutex_init(&d.print, NULL);
	return (d);
}

void	gen_philos(t_env *d)
{
	int	i;

	d->start_time = ft_get_time();
	i = -1;
	while (++i < d->num_ph)
	{
		d->philos[i].num = i + 1;
		d->philos[i].ko = 0;
		d->philos[i].d = d;
		pthread_mutex_init(&d->philos[i].time_mtx, NULL);
		pthread_mutex_init(&d->philos[i].round_mtx, NULL);
		pthread_create(&d->philos[i].tid, NULL, &routine, &d->philos[i]);
	}
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
