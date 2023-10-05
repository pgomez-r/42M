/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/05 17:10:18 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_monitor(t_env *d)
{
	int	i;
	int	finished;

	i = -1;
	finished = 0;
	while (++i < d->num_ph)
	{
		if (d->philos[i].ko == 1)
		{	
			d->ko = 1;
			return ;
		}
		if (d->philos[i].round == d->rounds)
			finished++;
	}
	if (finished == d->rounds)
		d->ko == 2;
}

void	routine(t_ph *ph)
{
	ph->fed_time = get_time();
	if (ph->num % 2 != 0)
		ft_usleep(10);
	while (1)
	{		
		pick_forks(ph);
		philo_eat(ph);
		drop_forks(ph);
		philo_sleep(ph);
		printf("Philo %d is thinking.\n");
	}
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
		return (1);
	gen_philos(&d);
	while (d.ko == 0)
		ft_monitor(&d);
	ft_free_env(&d);
	close_threads(&d);
	return (0);
}

/*Añadir, después de lanzar los hilos, una función monitoring*/