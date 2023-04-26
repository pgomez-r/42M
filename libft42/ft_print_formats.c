/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:28:36 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/04 14:02:31 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La mayoría de las funciones que vamos a usar para imprimir cada especificador
de formato ya las hemos escrito y usado en libft o la piscina, pero vamos a
añadirle siempre el puntero a la dirección de nuestro contador, para actualizarlo
siempre que imprimamos un char y haremos otras modificaciones para ajustarnos al
man de printf*/

#include "libft.h"

void	ft_putchari(int c, size_t *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstri(char *str, size_t *i)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchari(*str, i);
		str++;
	}
}

void	ft_putnbri(int n, size_t *i)
{
	if (n == -2147483648)
	{
		ft_putstri("-2147483648", i);
		return ;
	}
	if (n < 0)
	{
		ft_putchari('-', i);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbri(n / 10, i);
		ft_putchari(n % 10 + '0', i);
	}
	else
		ft_putchari(n + '0', i);
}

/*ft_putnbr recibe un entero y lo representa en pantalla, es decir, lo imprime
en chars se basa en el uso de recursividad, se llama así misma y, cada vez que
lo hace, envia el número dividido entre 10 (lo "descompone") y luego ,cuando 
termina de llamarse así misma, comienza a imprimir todos los restos (%10) de 
las divisiones, lo que será igual a cada último dígito del número entero 
(ej. 14%10 = 4)*/

void	ft_putunsigi(unsigned int n, size_t *i)
{
	if ((int)n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putunsigi(n / 10, i);
		ft_putchari(n % 10 + '0', i);
	}
	else
		ft_putchari(n + '0', i);
}

/*En el caso de %u, para unisgned int, hacemos un putnbr, pero como no
queremos que gestione negativos, necesitamos crear una función nueva que
no compruebe el número min negativo ni imprima el signo negativo antes del
resto de números, por lo demás, misma función*/

void	ft_puthexalli(unsigned long int n, char *base, size_t *i)
{
	char	c;

	if (n < 16)
	{
		c = base [n];
		ft_putchari(c, i);
	}
	if (n >= 16)
	{
		c = base [n % 16];
		n = n / 16;
		ft_puthexalli(n, base, i);
		ft_putchari(c, i);
	}
}

/*ft_puthexall tiene el mismo principio de que putnbr, pero como queremos
imprimir el valor en base hexadecimal, hacemos módulo/división de 16 para ir
descomponiendo el número, y luego usamos una cadena str que contiene la base
hexadecimal para obtener cada dígito, haciendo que putchar imprima el char
de la base corresponiente a la posicion de base [n/16] para poder usarlo 
tanto para %x como %X y %p, */