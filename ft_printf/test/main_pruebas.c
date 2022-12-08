/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pruebas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:21:42 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/08 11:45:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, size_t *i)
{
 	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(char *str, size_t *i)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, i);
		str++;
	}
}

void	ft_putnbr(int n, size_t *i)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", i);
		return ;
	}
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
	char	c;

	if (n < 16)
	{
		c = base [n];
		ft_putchar(c, i);
	}
	if (n >= 16)
	{
		c = base [n % 16];
		n = n / 16;
		ft_puthexall(n, base, i);
		ft_putchar(c, i);
	}
}

void	ft_checkformat(va_list arg, char *str, size_t *i)
{
	if (*str == 'c')
		ft_putchar(va_arg(arg, char), i);
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

int	main(void)
{
	// char	*str;

	// str = NULL;
	// ft_printf("Hola %s, %d, %c, %u, %x, %X, %p\n", "tu", 42, 'a', 42, 42, 42, 42);
	// printf("Hola %s, %d, %c, %u, %x, %X, %p\n", "tu", 42, 'a', 42, 42, 42, 42);
	printf("MIN %x\n", 483648);
	ft_printf("MIN %x\n", 483648);
	return (0);
}
