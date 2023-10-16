/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/16 21:17:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

void	*one_philo(void *param)
{
	t_ph	*ph;

	ph = (t_ph *)param;
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	pthread_mutex_lock(&ph->d->finish_mtx);
	while (ph->d->finish == 0)
	{		
		pthread_mutex_unlock(&ph->d->finish_mtx);
		pthread_mutex_lock(&ph->d->fork_mutex[0]);
		ft_log(ph, "has taken a fork.", YELLOW);
		return (0);
	}
	if (ph->d->finish != 0)
		pthread_mutex_unlock(&ph->d->finish_mtx);
	return (0);
}

void	*routine(void *param)
{
	t_ph	*ph;

	ph = (t_ph *)param;
	if (ph->num % 2 != 0)
		ft_usleep(2);
	pthread_mutex_lock(&ph->d->finish_mtx);
	while (ph->d->finish == 0)
	{		
		pthread_mutex_unlock(&ph->d->finish_mtx);
		if (ph->stat == 0)
			pick_forks(ph);
		if (ph->stat == 1)
			philo_eat(ph);
		if (ph->stat == 2)
			drop_forks(ph);
	}
	if (ph->d->finish != 0)
		pthread_mutex_unlock(&ph->d->finish_mtx);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	d;

	if (ac < 5 || ac > 6)
		return (ft_error("Wrong number of arguments\n", 0, &d), 1);
	if (!ft_args_digit(av))
		return (ft_error("Some/all arguments are not digits\n", 0, &d), 1);
	d = parse_params(av);
	if (d.num_ph < 1 || d.time_die < 1 || d.time_eat < 1 || d.time_sleep < 1)
		return (ft_error("Negative or zero values\n", 0, &d), 1);
	if (d.num_ph > 200)
		return (ft_error("Too many philosophers on the table!\n", 0, &d), 1);
	gen_philos(&d);
	pthread_mutex_lock(&d.finish_mtx);
	while (d.finish == 0)
	{	
		pthread_mutex_unlock(&d.finish_mtx);
		ft_monitor(&d);
	}
	return (ft_exit(&d), 0);
}
