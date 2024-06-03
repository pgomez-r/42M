/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:52:56 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/22 08:18:17 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
