/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 08:54:17 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctr;

	ctr = 0;
	if (size > 0)
	{	
		while (src[ctr] && ctr < (size - 1))
		{
			dest[ctr] = src [ctr];
			ctr++;
		}
		dest[ctr] = '\0';
	}
	while (src[ctr])
		ctr++;
	return (ctr);
}

/*Al igual que strlcat, esta función va a copiar una cadena sobre otra hasta un
maximo size de caracteres, pero el valor que devuelve no es la cadena en si, 
sino in size_t con el valor del número de caracteres que se han copiado*/