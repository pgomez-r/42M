/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/22 08:18:30 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
