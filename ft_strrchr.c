/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:23 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:40:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

/*Misma idea que la función strchr pero empezando a buscar desde el final de str
Esta función busca la última aparición de un caracter en un string, si el 
caracter a buscar es '\0' también lo encontrará, devolverá un puntero al 
caracter si lo encuentra o 0 si no lo encuentra
En vez de usar puntero, vamos a movernos con un contador con valor strlen de str
así nos situamos en la última posición de str, el if para comprobar si el final
de cadena es lo que busca ch lo hacemos lo primero, ya que empezamos por el final
Luego vamos haciendo len-- cada vez que s[len] no coincida con c, hasta llegar a
la posicion 0 (len >= 0), que también comprobamos, si no ha encontrado ninguna
coincidencia, return (NULL)
Igual que en strchr, lo que devolvemos es un puntero a la posición de s en la que
se produce la coincidencia, por lo que devolvemos s + len para que el puntero se
envíe "desplazado" a la posición correcta, además este debe ser casteado, ya que
recibe como parámetro en el prototipo un const char, pero debe devolver char*/