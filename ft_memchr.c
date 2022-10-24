/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:39:14 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 17:25:50 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*Esta función busca la primera aparición de un caracter en un string, si el
caracter a buscar es '\0' también lo encontrará, devolverá un puntero al 
caracter si lo encuentra o 0 si no lo encuentra

El prototipo recibe una cadena void*, así que para recorrerla vamos a crear
un cadena char y le asignamos el valor de s casteado a (char *)
El contador para recorrer la cadena lo declaramos como size_t también, ya que 
lo vamos a comparar con size_t n que recibe en el prototipo la función
Creamos bucle, mientras el contador sea menos que n, vamos recorriendo la cadena,
cuando encontremos que el char en la posicion actual es igual que c, devolvemos
la cadena con el puntero apuntando a la posicion donde lo ha encontrado (s + i)

Lo importante de esta función es el casteo: la cadena nueva (char *), cada char
del bucle para comparar (unisgned char), el puntero de cadena a devolver (char *)
y el contador size_t como n del prototipo*/