/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:20 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 17:02:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	cont;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	cont = len_dst;
	while (*src != '\0' && cont < (size - 1))
		*(dest + cont++) = *src++;
	*(dest + cont) = '\0';
	return (len_dst + len_src);
}

/*Esta función concatena 2 strings hasta un límite de caracteres, coge el src y
 * lo copia a partir del final del dest, pero la longitud empieza al principio
 * del dest, es decir, va a contar los caracteres de dest, va a copiar los que 
 * falten para llegar al size - 1 y ese último caracter será el final de línea*/