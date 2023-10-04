/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/04 21:59:56 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"
/*
void	print_values(t_env *d)
{
	printf("Number of philos: %d\n", d->num_ph);
	printf("Number of forks: %d\n", d->num_fks);
	printf("Time to die: %d\n", d->time_die);
	printf("Time to eat: %d\n", d->time_eat);
	printf("Time to sleep: %d\n", d->time_sleep);
	printf("Number of times to eat: %d\n", d->rounds);
}
*/

/*
void	op_selector(t_ph *ph)
{
	pick_forks();
	if (ph->stat == 0 && ph->flag == 0)
	{
		printf("Philo %d is thinking.\n");
		ph->flag = 1;
	}
	
}
*/

void	routine(t_ph *ph)
{
	// while (1) -> toda la rutina en bucle, activamos unas u otras funciones
	//					segun flags/estados/mutex_locks
	printf("Philo %d is thinking.\n");
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 1;
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		printf("Philo %d is eating.\n");
		ft_usleep((useconds_t)ph->d->time_eat);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ph->d->forks[ph->d->num_ph - 1] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 0;
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 1;
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 1;
		printf("Philo %d is eating.\n");
		ft_usleep((useconds_t)ph->d->time_eat);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 2]);
		ph->d->forks[ph->num - 2] = 0;
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ph->d->forks[ph->num - 1] = 0;
	}
	printf("Philo %d is sleeping.\n");
	ft_usleep((useconds_t)ph->d->time_eat);
}

void	gen_philos(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		d->philos[i].num = i + 1;
		pthread_create(&d->philos[i].tid, NULL, &routine, &d->philos[i]);
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
	return (0);
}

/*Añadir, después de lanzar los hilos, una función monitoring*/