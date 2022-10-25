/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:01:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:16:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] == s1[i] && i < n -1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*Esta función compara lexicograficamente 2 strings, caracter a caracter 
desde la posición inicial, cuando encuentra un char diferente, devuelve un int
que es el resultado de la diferencia entre los caracteres que encuentra, si no
encuentra ninguna diferencia, devuelve 0
la diferencia con strcmp es que compara un número máximo n de caracteres
nos movemos por las dos cadenas con un contador size_t (porque lo vamos a 
comparar con el size_t n dado por la función)
si n=0 devolvemos 0, en cualquier otro caso, recorremos str mientras se cumplan
3 condiciones: que no estemos en final de cadena s1, que el contenido de ambas en
la posicion del contador sea igual, que i sea menor que n - 1
cuando se deje de cumplir alguna de estas, devolvemos la diferencia de s1 y s2 en
la posicion del contador, casteados como unsigned char (man strncmp)

no me queda del todo claro por qué n - 1, entiendo que se supone que n va a ser
siempre el len total de s1, por lo que si n = 10, la posicion 10 será '\0'*/