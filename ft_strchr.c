/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/15 19:23:50 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	return (NULL);
}

/*Esta función busca la primera aparición de un caracter en un string, si el
 * caracter a buscar es '\0' también lo encontrará, devolverá un puntero al 
 * caracter si lo encuentra o 0 si no lo encuentra*/

/*Creamos un puntero nuevo, tipo char, le asignamos el valor de str casteado
como char en lugar de const char y hacemos un bucle mientras el contenido de ptr
sea diferente a c (casteado en char también)
cuando no lo sea, devolvemos p, que estará ya en la posición que coincide con c
Añadimos un if *p == fin de cadena, para devolver NULL, ya que no ha encontrado
coincidencias con c

Me da fallo con PACO "your strchr does not work with \0", pero yo lo pruebo y se 
comporta exactamente igual que la original strchr*/