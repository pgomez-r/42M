/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:04:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/08 17:35:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 8;
	while (--i >= 0)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
	}
}

// int	main(void)
// {
// 	print_bits('U');
// 	return (0);
// }
