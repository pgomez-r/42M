/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:23 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/15 20:09:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = ft_strlen(str);
	if (ch == 0)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

/*Misma idea que la función strchr pero empezando a buscar desde el final de str
Esta función busca la última aparición de un caracter en un string, si el 
caracter a buscar es '\0' también lo encontrará, devolverá un puntero al 
aracter si lo encuentra o 0 si no lo encuentra
En vez de usar puntero, vamos a movernos con un contador con valor strlen de str
así nos situamos en la última posición de str, el if para comprobar si el final
de cadena es lo que busca ch lo hacemos lo primeor, ya que empezamos por el final
Igual que con strch, PACO me lo tira abajo, pero yo paso las pruebas de paco
a "mano" con un main y se comporta como la función original*/