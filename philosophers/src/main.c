/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/08/04 19:03:13 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	gen_philos(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		d->philos[i].ph_id = i + 1;
		pthread_create(d->philos[i], NULL, check_action, );
	}
}

t_env	parse_params(char **av)
{
	t_env	d;
	int		i;

	d.num_ph = ft_atoi(av[1]);
	d.num_fks = d.num_ph;
	d.philos = malloc(sizeof(t_ph) * d.num_ph);
	d.forks = malloc(sizeof(int) * d.num_fks);
	d.fork_mutex = malloc(sizeof(pthread_mutex_t) * d.num_fks);
	i = -1;
	while (++i < d.num_fks)
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

void	print_values(t_env *d)
{
	printf("Number of philos: %d\n", d->num_ph);
	printf("Number of forks: %d\n", d->num_fks);
	printf("Time to die: %d\n", d->time_die);
	printf("Time to eat: %d\n", d->time_eat);
	printf("Time to sleep: %d\n", d->time_sleep);
	printf("Number of times to eat: %d\n", d->rounds);
}

int	main(int ac, char **av)
{
	t_env	d;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (!ft_args_digit(av))
		return (ft_putstr_fd("Some/all arguments are not digits\n", 2), 1);
	d = parse_params(av);
	if (d.num_fks < 1 || d.time_die < 1 || d.time_eat < 1 || d.time_sleep < 1)
		return (1);
	print_values(&d);
	gen_philos(&d);
	return (0);
}
