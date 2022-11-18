/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:28:36 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/18 20:04:18 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putchar(char c, size_t *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(char *str, size_t *i)
{
	while (*str)
	{
		ft_putchar(*str, i);
		str++;
	}
}

void	ft_putnbr(int n, size_t *i)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", i);
	if (n < 0)
	{
		ft_putchar('-', i);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		ft_putchar(n % 10 + '0', i);
	}
	else
		ft_putchar(n + '0', i);
}
