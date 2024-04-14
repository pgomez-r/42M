/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:06:58 by pgruz             #+#    #+#             */
/*   Updated: 2024/04/04 18:10:39 by pgomez-r         ###   ########.fr       */
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
		usleep(1000);
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
			if ((av[i][j] == '+' || av[i][j] == '-')
				&& ft_isdigit(av[i][j + 1]))
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(char **args, t_env *d)
{
	if (d->num_ph > 200)
		return (ft_error("too many philosophers on the table!\n", 1, d), 1);
	if (d->num_ph < 1 || d->time_die < 60 || d->time_eat < 60
		|| d->time_sleep < 60)
		return (ft_error("values don't meet minimum required\n", 1, d), 1);
	if (args[5] != NULL && d->rounds < 0)
		return (ft_error("num of times to eat can't be negative!\n", 1, d), 1);
	if (d->time_die > INT_MAX || d->time_eat > INT_MAX
		|| d->time_sleep > INT_MAX)
		return (ft_error("times values exceed INT_MAX\n", 1, d), 1);
	return (0);
}
