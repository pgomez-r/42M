/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 08:13:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*Esta función aloja suficiente memoria para copiar s1, hace la copia y devuelve
un puntero al string, si no se pudo asignar la memoría devuelve NULL
Primero calculamos el tamaño de la cadena src con strlen, reservamos memoria con
malloc para char* tamaño char * len + 1 (para añadir luego '\0') luego recorremos
la cadena aumentando un contador y vamos copiando [i] de src a [i] de dup
cuando termine de copiar, cerramos la ultima posicion de la nueva cadena con '0'
y la devolvemos*/