/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:43:02 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/02 21:27:04 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char const *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sig;
	int		num;

	sig = 1;
	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	if (ft_isdigit((int) *str) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{	
		num = (*str - '0') + (num * 10);
		str++;
	}
	return (num * sig);
}

/*SIN TERMINAR -> Idea: cuando hay error, llamar a esta función, 
pasarle el mensaje a imprimir, la struct general y un código de ejecución
Cod 0 = nada que liberar
Cod 1 = liberar los parámetros de la struct general
Cod 2 = llamar a función para destruir/liberar mutex + struct general*/

void	ft_error(char *msg, int code, t_env *d)
{
	ft_putstr_fd(msg, 2);
	if (code == 0)
		return ;
	if (code == 1)
		ft_free_env(d);
}
