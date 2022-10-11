/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:33:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/11 13:44:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*Esta función designa memoria y devuelve una cadena nueva que es
una copia de una porción de la cadena dada en el prototipo
La porción a copiar será dede la posición de la cadena que marque start
y tantos bytes siguientes como sea el valor de len*/

/*Creamos un contador i y un char * para la nueva cadena y le asignamos memoria
con malloc, de tamaño len + 1 (para luego añadir '\0' la final de cadena) 
Luego, como siempre, hacemos el if (comprobación) para retornar 
NULL si no se pudiese asiganar la memoria*/

/*Luego es solo crear un bucle para ir copiando desde start hasta len,
mientras el contador sea menor que len, copiamos a str y seguimos aumentando i
Para terminar cerramos la cadena con '\0' y hacemos return(str)*/