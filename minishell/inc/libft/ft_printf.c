/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:06 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/24 15:20:58 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función imprime uno a uno cada char de la cadena que entra como primer 
parámetro y cuando encuentra un % dentro de esta, comprueba a qué tipo de 
variable hace referencia, la obtiene desde los argumentos (va_list/va_arg) y 
luego la convierte a char, en el formato deseado, para poder imprimirla caracter 
a caracter en pantalla.

Necesitamos 1)función para comprobar el tipo de variable de cada argumento 
(comprobando que caracter hay en la posición después del %) 2)comprender y usar
los macros va_list, va_start, va_arg y va_end 3)varias funciones para convertir
cada tipo(s) de variable a char en el formato correcto para imprimir 4)contador 
que aumente con cada char que se imprima, para el return final. */

#include "libft.h"

void	ft_checkprintformat(va_list args, char *str, size_t *i)
{
	if (*str == 'c')
		ft_putchari(va_arg(args, int), i);
	else if (*str == 's')
		ft_putstri(va_arg(args, char *), i);
	else if (*str == '%')
		ft_putchari(*str, i);
	else if ((*str == 'd') || (*str == 'i'))
		ft_putnbri(va_arg(args, int), i);
	else if (*str == 'u')
		ft_putunsigi(va_arg(args, unsigned int), i);
	else if (*str == 'x')
		ft_puthexalli(va_arg(args, unsigned int), "0123456789abcdef", i);
	else if (*str == 'X')
		ft_puthexalli(va_arg(args, unsigned int), "0123456789ABCDEF", i);
	else if (*str == 'p')
	{
		ft_putstri("0x", i);
		ft_puthexalli(va_arg(args, unsigned long int), "0123456789abcdef", i);
	}
}

/*a ft_checkformat le llega el siguiente carácter después de % (y el contador)
tiene un if con cada especificador de formato que pide el subject y en cada
caso llama a una función para que lo imprima, enviando también el contador*/

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, str);
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_checkprintformat(args, (char *)str, &i);
		}
		else
			ft_putchari(*str, &i);
		str++;
	}
	va_end(args);
	return (i);
}

/*Declaramos una estructura va_list donde se guardaran los argumentos(args)
y un contador que aumentará con cada char que se imprima, para el return.
Llamamos al macro va_start y le pasamos args y str (la variable va_list, y 
el último parámetro conocido de ft_print), esto inicializa la lista de 
argumentos. Si la cadena de caracteres es nula, la rellenamos con "(null)"
para que sea lo que se imprima luego en pantalla. Ahora vamos desplazando 
un puntero a lo largo de str para comprobar cada char, si no es % lo imprimimos
con putchar y seguimos aumentando el puntero, si es % aumentamos el puntero y
llamamos a checkformat (aumentamos el puntero antes, para que el char que llegue
a check sea el siguiente después de %)

Para mantener contorlado el contador de caracteres impresos: cada caracter se 
imprime con putchar (todas las funciones para cada tipo de argumento terminan 
llamando a putchar), cada vez que se ejecuta putchar termina en i++ 
Es importante pasarlo de una función a otra y que no se pierda o cambie, yo 
utilizo dirección/puntero, por lo que cuando llamo a checkformat o a putchar
en la función principal (donde se ha declarado el contador por primera vez)
lo que se envía es la dirección de la variable &i y luego aumentamos el valor
que se encuentra en esa dirección +1 (*i)++*/