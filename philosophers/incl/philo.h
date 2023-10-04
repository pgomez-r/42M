/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:58:34 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/04 21:56:41 by pgomez-r         ###   ########.fr       */
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

typedef struct s_env
{
	int				num_ph;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	int				rounds;
	int				ko;
	int				full;
	t_ph			*philos;
	int				*forks;
	pthread_mutex_t	*fork_mutex;
}	t_env;

typedef struct s_ph
{
	struct s_env	*d;
	pthread_t		tid;
	int				num;
	int				round;
	int				stat;
	int				print;
}	t_ph;

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
void				ft_error(char *msg, int code, t_env *d);

/*utils_2.c*/
u_int64_t			get_time(void);
int					ft_usleep(useconds_t time);
void				ft_free_env(t_env *d);

#endif