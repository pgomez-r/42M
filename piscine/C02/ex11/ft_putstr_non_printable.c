/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:21 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/01 11:34:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*ptr;
	char	*hexa;
	int		char_a;
	int		char_b;

	hexa = "0123456789ABCDEF";
	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr < 32 || *ptr == 127)
		{	
			write(1, "\\", 1);
			char_a = *ptr / 2;
			ft_putchar(hexa[char_a] + '0');
			char_b = *ptr % 2;
			ft_putchar(hexa[char_b] + '0');
		}
		else
			ft_putchar(*ptr);
		ptr++;
	}
}
