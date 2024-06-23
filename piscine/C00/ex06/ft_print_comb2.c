/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:52:34 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/06 18:41:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	impresora(int contador_a, int contador_b)
{
	ft_putchar(contador_a / 10 + '0');
	ft_putchar(contador_a % 10 + '0');
	write(1, " ", 1);
	ft_putchar(contador_b / 10 + '0');
	ft_putchar(contador_b % 10 + '0');
	if (contador_a < 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	contador_a;
	int	contador_b;

	contador_a = 0;
	while (contador_a <= 98)
	{
		contador_b = contador_a + 1;
		while (contador_b <= 99)
		{
			impresora(contador_a, contador_b);
			contador_b++;
		}
		contador_a++;
	}
}

int	main()
{
	ft_print_comb2();
}