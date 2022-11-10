/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:12:10 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/24 10:03:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n)
{
	write (1, &n, 1);
}

void	ft_print_combn(int n)
{
	if (n != (10 - n))
	{
		ft_print_combn(n / 10);
		ft_putchar(n % 10);
	}
}
