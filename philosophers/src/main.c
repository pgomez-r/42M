/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/19 21:10:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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
	int	stat = 0;

	ph = (t_ph *)param;
	if (ph->num % 2 != 0)
		ft_usleep(10);
	while (stat == 0)
	{		
		pick_forks(ph);
		philo_eat(ph);
		drop_forks(ph);
		philo_sleep(ph);
		ft_log(ph, "is thinking.", MAG);
		pthread_mutex_lock(&ph->d->finish_mtx);
		stat = ph->d->finish;
		pthread_mutex_unlock(&ph->d->finish_mtx);
	}
	// if (ph->d->finish != 0)
	// 	pthread_mutex_unlock(&ph->d->finish_mtx);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	d;
	int		stat = 0;

	if (ac < 5 || ac > 6)
		return (ft_error("wrong number of arguments\n", 0, &d), 1);
	if (!ft_args_digit(av))
		return (ft_error("some arguments are not digits\n", 0, &d), 1);
	d = parse_params(av);
	if (d.num_ph > 200)
		return (ft_error("too many philosophers on the table!\n", 1, &d), 1);
	if (d.num_ph < 1 || d.time_die < 60 || d.time_eat < 60 || d.time_sleep < 60)
		return (ft_error("values don't meet minimum required\n", 1, &d), 1);
	if (av[5] != NULL && d.rounds < 0)
		return (ft_error("num of times to eat can't be negative!\n", 1, &d), 1);
	if (d.time_die > INT_MAX || d.time_eat > INT_MAX || d.time_sleep > INT_MAX)
		return (ft_error("times values exceed INT_MAX\n", 1, &d), 1);
	gen_philos(&d);
	while (stat == 0)
	{	
		ft_monitor(&d);
		pthread_mutex_lock(&d.finish_mtx);
		stat = d.finish;
		pthread_mutex_unlock(&d.finish_mtx);
	}
	return (ft_exit(&d), 0);
}
