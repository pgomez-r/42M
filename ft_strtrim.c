/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:33:57 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 13:11:34 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Esta función nos va a recortar una cadena char, eliminando del principio y 
final de la misma los caracteres "vacios" (espacios, saltos...), que están 
especificados por set (otra cadena char)
Para hacerlo, creamos otra función con la que nos vamos a "mover" dentro de set
Desde la función princial la vamos a enviar un char cada vez a la funcion nueva,
y lo vamos a ir comparando 1 a 1 por cada caracter de set*/

int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/*En la función principal vamos a crear tres contadores: start, end, i
tart y end comienzan en la posicion inicial y final (respectv) de s1
Usando check_set, hacemos un while para start y otro para end, vamos a 
hacer que ambos se muevan por la cadena, star de izq a der, end al reves,
hasta que el contenido de ambas posiciones en s1 sea diferente de set
Primero hacemos el while de start, y cuando esta tenga su valor final,
iniciamos end con strlen(s1) y comenzamos a hacer misma operación pero
restandole valor a end-- cada vez que se cunpla while
Cuando tenemos los valores finales de start y end, asignamos memoria para 
la cadena nueva con el tamaño de end - start + 1
Por ultimo copiamos la s1 en str con un while y cerramos '\0' cuando termine*/

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

/* why malloc sizeof s1 en lugar de sizeof(char const *) 
qué pasaría si la cadena tiene espacios y caracteres del set en mitad
p ej "  \n\t\n  Hola42  \n\t quedisecabesa   \t\n"*/