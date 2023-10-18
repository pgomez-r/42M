/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:58:34 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/17 22:35:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define ORANGE "\033[0;38;5;208m"
# define GRN "\e[1;92m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define RESET "\033[0m"

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

/*Variables que de momento no uso, puede que termine borrando
		ph->ko (le asigno valor en monitoring, pero no la uso)
		env->forks (array de int para tenedores, les doy 0/1 cuando
			se agarran, pero de momento no lo uso para nadam más)
*/

typedef struct s_ph
{
	struct s_env		*d;
	pthread_t			tid;
	time_t				fed_time;
	pthread_mutex_t		time_mtx;
	int					num;
	int					round;
	pthread_mutex_t		full_mtx;
	int					full;
}	t_ph;

typedef struct s_env
{
	int				num_ph;
	time_t			start_time;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	int				rounds;
	int				finish;
	pthread_mutex_t	finish_mtx;
	t_ph			*philos;
	int				*forks;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print;
	int				ko;
	pthread_mutex_t	ko_mtx;
}	t_env;

/*main.c*/
void				*routine(void *param);
void				*one_philo(void *param);

/*init.c*/
void				gen_philos(t_env *d);
t_env				parse_params(char **av);
int					ft_args_digit(char **av);
void				init_env_struct(t_env *d);

/*actions.c*/
void				pick_forks(t_ph *ph);
void				drop_forks(t_ph *ph);
void				philo_eat(t_ph	*ph);
void				philo_sleep(t_ph *ph);
void				ft_monitor(t_env *d);

/*utils.c*/
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char const *s, int fd);
long int			ft_atoi(const char *str);
int					ft_isdigit(int c);

/*utils_2.c*/
time_t				ft_get_time(void);
int					ft_usleep(time_t time);
void				ft_log(t_ph *ph, char *msg, char *color);
int					check_ko(t_env *d, t_ph *ph);
int					check_meals(t_env *d);

/*exit.c*/
void				ft_destroy_mutex(t_env *d);
void				close_threads(t_env *d);
void				ft_error(char *msg, int code, t_env *d);
void				ft_free_env(t_env *d);
void				ft_exit(t_env *d);

#endif
