/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:42:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:26:08 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*array;
	size_t	i;

	array = ((char *)malloc(n * size));
	i = 0;
	if (array == 0)
		return (0);
	while (i < n * size)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}

/*Esta función aloja de forma contigua espacio para n objetos, cada uno de size 
bytes de memoria y devuelve un puntero a la memoria alojada, esta memoria se
llena con bytes de valor 0
Una forma más segura (pero más lenta) que malloc para reservar memoria para 
ya que se asegura de dejar esa memoria "vacía", con valor 0
Para diseñarla nosotros, creamos una variable de tipo cadena char, reservamos
memoria para esta con malloc, pasando los parámetros n y size que recibe nuestra
función en su prototipo, y una vez comprobado que se ha podido reservar dicha
memoria, recorremos todas las posiciones de la cadena, una a una, asignandoles
valor 0, finalmente, devolvemos array casteado como void* (para coincidir con
el prototipo dado para calloc en man)*/ 