/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:53 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/13 14:04:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (dest < src)
	{
		i = 0;
		while (i < count)
		{
			*(unsigned char *) dest + i = *(unsigned char *) src + i;
			i++;
		}	
	}
	else
	{
		i = count - 1;
		while (i >= 0)
		{
			*(unsigned char *) dest + i = *(unsigned char *) src + i;
			i--;
		}	
	}
	return (dest);
}

/*Esta función copia de forma no destructiva, si el recurso y el destino se
 * solapan lo hará de forma que se pueda completar la copia*/
/*si el src es menor que el destino empezamos a copiar desde detrás hacia 
 * adelante (primera condición)*/
/* si no simplemente copiamos de izquierda a derecha*/