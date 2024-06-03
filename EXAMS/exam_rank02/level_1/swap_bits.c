/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:48:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/08 19:39:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	octet = (octet & 0b11110000) >> 4 | (octet & 0b00001111) << 4;
	return (octet);
}

// void	print_bits(unsigned char octet)
// {
// 	int		i;
// 	char	c;

// 	i = 8;
// 	while (--i >= 0)
// 	{
// 		c = ((octet >> i) & 1) + '0';
// 		write(1, &c, 1);
// 	}
// }

// int	main(void)
// {
// 	unsigned char	c;

// 	c = 'H';
// 	print_bits(c);
// 	write(1, "\n", 1);
// 	c = swap_bits(c);
// 	print_bits(c);
// 	return (0);
// }
