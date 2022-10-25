/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 17:40:52 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cpy;
	char	*src_cpy;
	size_t	i;

	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}

/*Copia n número de bytes del espacio de memoria de src al de dest, si ambos se
sobreponen, el comportamiento de la función no está definido (man), 3 variables: 
un contador y dos punteros a cadena char, que son para darles el valor de dest 
y src del prototipo casteados y asi poder movernos por las cadenas
Mientras el contador sea menor que el valor de n, vamos copiando 1 a 1 cada
valor de una cadena a otra, luego devolvemos dest*/