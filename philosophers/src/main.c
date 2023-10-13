/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/13 15:37:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

void	ft_monitor(t_env *d)
{
	int	i;
	int	aux;

	i = -1;
	aux = 0;
	while (++i < d->num_ph)
	{
		if (check_ko(d, &d->philos[i]) == 1)
		{	
			pthread_mutex_lock(&d->finish_mtx);
			d->finish = 1;
			pthread_mutex_unlock(&d->finish_mtx);
			return ;
		}
		pthread_mutex_lock(&d->philos[i].round_mtx);
		if (d->philos[i].round == d->rounds)
			aux++;
		pthread_mutex_unlock(&d->philos[i].round_mtx);
	}
	if (aux == d->rounds)
	{
		pthread_mutex_lock(&d->finish_mtx);
		d->finish = 2;
		pthread_mutex_unlock(&d->finish_mtx);
	}
}

/*Cambiar fed_time = ft_get_time por -- fed_time = start_time?
Cambiar while a (1) y pasar el if flag_finish a cada action?*/
void	*routine(void *param)
{
	t_ph	*ph;

	ph = (t_ph *)param;
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	if (ph->num % 2 != 0)
		ft_usleep(10);
	pthread_mutex_lock(&ph->d->finish_mtx);
	while (ph->d->finish == 0)
	{		
		pthread_mutex_unlock(&ph->d->finish_mtx);
		pick_forks(ph);
		philo_eat(ph);
		drop_forks(ph);
		philo_sleep(ph);
		ft_log(ph, "is thinking.", MAG);
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
	close_threads(&d);
	ft_destroy_mutex(&d);
	if (d.finish == 2)
		printf("%sAll philosophers are fed and happy =)\n\033[0m", GRN);
	ft_free_env(&d);
	return (0);
}

/*Añadir, después de lanzar los hilos, una función monitoring*/