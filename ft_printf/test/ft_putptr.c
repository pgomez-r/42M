/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:53:58 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/22 08:18:23 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_long(unsigned long int n, size_t *i)
{
	char	str[20];
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (n == 0)
		ft_putchar('0', i);
	while (n != 0)
	{
		str[j] = base[n % 16];
		n = n / 16;
		j++;
	}
	while (j--)
		ft_putchar(str[j], i);
}

void	ft_putptr(unsigned long int n, size_t *i)
{
	ft_putchar('0', i);
	ft_putchar('x', i);
	ft_printhex_long(n, i);
}
