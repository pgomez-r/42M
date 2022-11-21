/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:28:36 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/21 16:50:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putchar(int c, size_t *i)
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

void	ft_putunsig(unsigned int n, size_t *i)
{
	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putunsig(n / 10, i);
		ft_putchar(n % 10 + '0', i);
	}
	else
		ft_putchar(n + '0', i);
}

void	ft_puthexall(unsigned long int n, char *base, size_t *i)
{
	char	str[20];
	int		j;

	j = 0;
	if (n == 0)
		ft_putchar('0', i);
	while (n != 0)
	{
		str[j] = base [n % 16];
		n = n / 16;
		j++;
	}
	while (j--)
		ft_putchar(str[j], i);
}
