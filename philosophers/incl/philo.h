/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:58:34 by pgruz             #+#    #+#             */
/*   Updated: 2023/08/23 14:09:56 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

typedef struct s_ph
{
	pthread_t	tid;
	int			ph_id;
}	t_ph;

typedef struct s_env
{
	int				num_ph;
	int				num_fks;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				rounds;
	t_ph			*philos;
	int				*forks;
	pthread_mutex_t	*fork_mutex;
}	t_env;

/*main.c*/
void				check_action(t_env *d);
void				gen_philos(t_env *d);

/*parse.c*/
t_env				parse_params(char **av);
int					ft_args_digit(char **av);

/*utils.c*/
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char const *s, int fd);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);

#endif