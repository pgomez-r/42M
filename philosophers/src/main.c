/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/20 16:33:52 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*one_philo(void *param)
{
	t_ph	*ph;
	int		stat;

	ph = (t_ph *)param;
	stat = 0;
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	while (stat == 0)
	{		
		pthread_mutex_lock(&ph->d->fork_mutex[0]);
		ft_log(ph, "has taken a fork", YELLOW);
		update_stat(&stat, ph->d);
		return (0);
	}
	return (0);
}

void	*routine(void *param)
{
	t_ph	*ph;
	int		stat;

	ph = (t_ph *)param;
	stat = 0;
	if (ph->num % 2 != 0)
		ft_usleep(10);
	while (stat == 0)
	{		
		pick_forks(ph);
		philo_eat(ph);
		drop_forks(ph);
		philo_sleep(ph);
		ft_log(ph, "is thinking", MAG);
		update_stat(&stat, ph->d);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_env	d;
	int		stat;

	stat = 0;
	if (ac < 5 || ac > 6)
		return (ft_error("wrong number of arguments\n", 0, &d), 1);
	if (!ft_args_digit(av))
		return (ft_error("some arguments are not digits\n", 0, &d), 1);
	d = parse_params(av);
	if (check_argv(av, &d))
		return (1);
	gen_philos(&d);
	while (stat == 0)
	{	
		ft_monitor(&d);
		update_stat(&stat, &d);
	}
	return (ft_exit(&d), 0);
}
