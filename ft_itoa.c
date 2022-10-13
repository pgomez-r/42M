/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:44:23 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/13 13:45:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ?¿ PUEDO/DEBO INCLUIR ESTA FUNCIÓN EN LIBFT.H ¿? */
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
	{
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	}
	else if (n < 10)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

/*Esta función recibe un entero (neg o pos) y lo devuelve representado
en una cadena char
Vamos a usar la idea base de putnbr (recursividad) pero con strcpy en lugar
de putchar, ya que no nos pide "imprimir" uno a uno los char de la cadena, 
sino crear una cadena nueva y completa que represente al número int
La idea es = recursivamente, vamos haciendo una mini cadena de cada dígito
(strcpy) y las vamos uniendo una a otra (strjoin)*/

/*creamos un char* para la cadena nueva, 
le asignamos memoria con malloc char * 2, como se va a usar recursivamente, 
solo necesitamos dos espacios en cada "uso", uno para el dígito, otro para '\0'
añadimos el if de comprobación por si no se ha podido asignar memoria*/

/*añadimos otro if para menor int posible, si sucede, escribir a caraperro*/