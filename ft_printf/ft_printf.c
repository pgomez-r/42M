/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:06 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/21 16:49:29 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_checkformat(va_list arg, char *str, size_t *i)
{
	if (*str == 'c')
		ft_putchar(va_arg(arg, int), i);
	else if (*str == 's')
		ft_putstr(va_arg(arg, char *), i);
	else if (*str == '%')
		ft_putchar(*str, i);
	else if ((*str == 'd') || (*str == 'i'))
		ft_putnbr(va_arg(arg, int), i);
	else if (*str == 'u')
		ft_putunsig(va_arg(arg, unsigned int), i);
	else if (*str == 'x')
	{	
		ft_puthexall(va_arg(arg, unsigned int), "0123456789abcdef", i);
	}
	else if (*str == 'X')
	{	
		ft_puthexall(va_arg(arg, unsigned int), "0123456789ABCDEF", i);
	}
	else if (*str == 'p')
	{
		ft_putstr("0x", i);
		ft_puthexall(va_arg(arg, unsigned long int), "0123456789abcdef", i);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	size_t	i;

	i = 0;
	va_start(arg, str);
	if (!str)
	{
		str = "(null)";
		va_end(arg);
	}
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_checkformat(arg, (char *)str, &i);
		}
		else
			ft_putchar(*str, &i);
		str++;
	}
	va_end(arg);
	return (i);
}
