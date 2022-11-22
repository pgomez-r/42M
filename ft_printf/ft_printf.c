/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:06 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/22 16:33:40 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
La función imprime uno a uno cada char de la cadena que entra como primer 
parámetro y cuando encuentra un % dentro de esta, comprueba a qué tipo de 
variable hace referencia, la obtiene desde los argumentos (va_list/va_arg) y 
luego la convierte a char, en el formato deseado, para poder imprimirla caracter 
a caracter en pantalla.

Necesitamos 1)función para comprobar el tipo de variable de cada argumento 
(comprobando que caracter hay en la posición después del %) 2)comprender y usar
los macros va_list, va_start, va_arg y va_end 3)varias funciones para convertir
cada tipo(s) de variable a char en el formato correcto para imprimir 4)contador 
que aumente con cada char que se imprima, para el return final. 

Cada caracter se imprime con putchar (todas las funciones para cada tipo de 
argumento terminan llamando a putchar), cada vez que se ejecuta putchar termina 
en i++ Es importante pasarlo de una función a otra y que no se pierda o cambie, 
yo utilizo dirección/puntero
*/

#include "ft_printf.h"

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
		ft_puthexall(va_arg(arg, unsigned int), "0123456789abcdef", i);
	else if (*str == 'X')
		ft_puthexall(va_arg(arg, unsigned int), "0123456789ABCDEF", i);
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
