/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:33:57 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:44:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

/*Esta función nos va a recortar una cadena char, eliminando del principio y 
final de la misma los caracteres "vacios" (espacios, saltos...), que están 
especificados por set (otra cadena char)
Para hacerlo, creamos otra función con la que nos vamos a "mover" dentro de set
Desde la función princial le vamos a enviar un único char cada vez a la funcion 
nueva, y lo vamos a ir comparando con cada uno de los caracteres de set

En la función principal vamos a crear tres contadores: start, end, i
start y end comienzan en la posicion inicial y final (respectv) de s1
Usando check_set, hacemos un while para start y otro para end, vamos a 
hacer que ambos se muevan por la cadena, star de izq a der, end al reves,
hasta que el contenido de ambas posiciones en s1 sea diferente de set
Primero hacemos el while de start, y cuando esta tenga su valor final,
iniciamos end con strlen(s1) y comenzamos a hacer misma operación pero
restandole valor a end-- cada vez que se cumpla while
Cuando tenemos los valores finales de start y end, asignamos memoria para 
la cadena nueva con el tamaño de end - start + 1
Por ultimo copiamos la s1 en str con un while y cerramos '\0' cuando termine*/