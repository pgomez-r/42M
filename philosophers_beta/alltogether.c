#include "philo.h"

void	close_threads(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
		pthread_join(d->philos[i].tid, NULL);
}

void	ft_destroy_mutex(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		pthread_mutex_destroy(&d->fork_mutex[i]);
		pthread_mutex_destroy(&d->philos[i].time_mtx);
		pthread_mutex_destroy(&d->philos[i].full_mtx);
	}
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->finish_mtx);
}

void	ft_free_env(t_env *d)
{
	if (d->philos)
		free (d->philos);
	if (d->forks)
		free (d->forks);
	if (d->fork_mutex)
		free (d->fork_mutex);
}

void	ft_error(char *msg, int code, t_env *d)
{
	ft_putstr_fd(msg, 2);
	if (code == 0)
		return ;
	if (code == 1)
		ft_free_env(d);
}

void	ft_exit(t_env *d)
{
	close_threads(d);
	ft_destroy_mutex(d);
	if (d->finish == 2)
		printf("%sAll philosophers are fed and happy =)\n\033[0m", GRN);
	ft_free_env(d);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

time_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*Mejora de usleep para que sea más fiable*/
int	ft_usleep(time_t time)
{
	time_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(10);
	return (0);
}

void	ft_log(t_ph *ph, char *msg, char *color)
{
	time_t	time;

	pthread_mutex_lock(&ph->d->print);
	time = ft_get_time() - ph->d->start_time;
	pthread_mutex_lock(&ph->d->finish_mtx);
	if (ph->d->finish == 0)
		printf("%s[%ld]--philo[%d]--%s\n\033[0m", color, time, ph->num, msg);
	pthread_mutex_unlock(&ph->d->finish_mtx);
	pthread_mutex_unlock(&ph->d->print);
}

int	check_ko(t_env *d, t_ph *ph)
{
	time_t	time;

	time = ft_get_time();
	pthread_mutex_lock(&ph->time_mtx);
	if ((time - ph->fed_time) >= d->time_die)
	{
		ft_log(ph, "had died.", RED);
		return (pthread_mutex_unlock(&ph->time_mtx), 1);
	}
	return (pthread_mutex_unlock(&ph->time_mtx), 0);
}

int	check_meals(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		pthread_mutex_lock(&d->philos[i].full_mtx);
		if (d->philos[i].full == 0)
			return (pthread_mutex_unlock(&d->philos[i].full_mtx), 0);
		pthread_mutex_unlock(&d->philos[i].full_mtx);
	}
	return (1);
}

void	pick_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
	}
	else
	{
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 2]);
		ft_log(ph, "has taken a fork.", YELLOW);
		pthread_mutex_lock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has taken a fork.", YELLOW);
	}
}

void	drop_forks(t_ph *ph)
{
	if (ph->num == 1)
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->d->num_ph - 1]);
		ft_log(ph, "has left a fork.", ORANGE);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has left a fork.", ORANGE);
	}
	else
	{
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 2]);
		ft_log(ph, "has left a fork.", ORANGE);
		pthread_mutex_unlock(&ph->d->fork_mutex[ph->num - 1]);
		ft_log(ph, "has left a fork.", ORANGE);
	}
}

void	philo_eat(t_ph	*ph)
{
	ft_log(ph, "is eating.", GREEN);
	pthread_mutex_lock(&ph->time_mtx);
	ph->fed_time = ft_get_time();
	pthread_mutex_unlock(&ph->time_mtx);
	while (1)
	{
		pthread_mutex_lock(&ph->time_mtx);
		if ((ft_get_time() - ph->fed_time) >= ph->d->time_eat)
		{
			pthread_mutex_unlock(&ph->time_mtx);
			ph->round++;
			if (ph->round == ph->d->rounds)
			{	
				pthread_mutex_lock(&ph->full_mtx);
				ph->full = 1;
				pthread_mutex_unlock(&ph->full_mtx);
			}
			return ;
		}
		pthread_mutex_unlock(&ph->time_mtx);
	}
}

void	philo_sleep(t_ph *ph)
{
	time_t	now;

	ft_log(ph, "is sleeping.", CYN);
	now = ft_get_time();
	while (1)
	{
		if ((ft_get_time() - now) >= ph->d->time_sleep)
			return ;
	}
}

void	ft_monitor(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		if (check_ko(d, &d->philos[i]) == 1)
		{	
			pthread_mutex_lock(&d->finish_mtx);
			d->finish = 1;
			pthread_mutex_unlock(&d->finish_mtx);
			return ;
		}
	}
	if (check_meals(d))
	{
		d->finish = 2;
		return ;
	}
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
	d.start_time = 0;
	d.finish = 0;
	pthread_mutex_init(&d.print, NULL);
	pthread_mutex_init(&d.finish_mtx, NULL);
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

void	*routine(void *param)
{
	t_ph	*ph;

	ph = (t_ph *)param;
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
	return (ft_exit(&d), 0);
}