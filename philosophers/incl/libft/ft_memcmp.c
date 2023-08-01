/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 17:27:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/*Esta función compara byte por byte s1 y s2, ambas de tamaño n, devuelve
0 si son iguales, si no, devulve la diferencia entre los dos primeros bytes que 
encuentra diferentes, casteados como (unsigned char)
Creamos dos punteros char a los que les daremos valor de s1 y s2 casteados en
punteros char también (para que coincidan los tipos de variable)
Creamos un contador, de tipo size_t (para coincidir con n) y empezamos un loop
Mientras que i < n iremos aumentando el contador para recorrer ambas cadenas,
si en algún momento el valor de la posicion byte de cada cadena no es el mismo,
devolvemos al momento la diferencia entre ambos bytes, casteada como unsigned 
char (para coindicir con los detalles de man memcmp) y la función termina aquí
Si, por el contrario, se termina de recorrer ambas cadenas sin encontrar diffs,
devolvemos 0 
Igual que en otras funciones de mem, lo más importante es tener presente los 
tipos de variables y castear para que siempre coincidan en comparaciones o al 
pasarlas de/a los prototipos de las funciones*/