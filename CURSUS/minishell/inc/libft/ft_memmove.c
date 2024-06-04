/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:53 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/22 11:33:17 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	int	i;

	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		i = 0;
		while (i < (int)count)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = count - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dest);
}

/*Esta función copia de forma no destructiva, si el source y el destino se
solapan lo hará de forma que se pueda completar la copia, así que hacemos 
un proceso parecido al de memcpy, pero con dos supuestos: if dest<src y else
If dest es menor que src, copiamos de "izq a der" hasta count bytes
Si el src es menor que el destino empezamos a copiar desde detrás hacia 
adelante, asignando a al contador i el valor de count - 1 y moviendolo con i--
*/
