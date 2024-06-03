/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:59:49 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/28 19:53:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	base_pos(char *base, char c)
{
	int		i = -1;

	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	while (base[++i] != '\0')
	{
		if (c == base[i])
			return (i);
	}
	return (i);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	num = 0;
	int	sig = 1;
	int	i = 0;
	char	*base = "0123456789abcdef";

	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	while (str[i] != '\0' && (base_pos(base, str[i]) < str_base))
	{
		num = (num * str_base) + base_pos(base, str[i]);
		i++;
	}
	return (num * sig);
}

int	main(int ac, char **av)
{
	int	num;
	int	base;

	if (ac != 3)
		return (printf("Wrong number of arguments!\n"), 1);
	base = atoi(av[2]);
	num = ft_atoi_base(av[1], base);
	printf("Num en base 10: %d\n", num);
	return (0);
}
