/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:43:02 by pgruz             #+#    #+#             */
/*   Updated: 2023/08/23 14:04:25 by pgruz            ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * TODO -> Function to improve usleep so it works more accuratly
 * 
 */