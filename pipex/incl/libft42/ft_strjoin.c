/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:06 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/27 21:19:56 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/*la función debe asignar memoria y devolver una cadena que termine
en '\0'
si la asiganción de memoria falla, return NULL
primero, declaramos 3 variables: dos contadores y la cadena final 
con malloc, asignamos el espacio necesario para la nueva cadena, calculado con
strlen de las dos cadenas iniciales + 1 (el más uno, para añadir al final '\0')
luego hacemos dos bucles while para ir copiando uno a uno cada byte de s1 primero
y luego continuar con s2, cuando empecemos a copiar s2, el indice para movernos 
por str será [i+j] al final, asignamos '\0' a la ultima posicion de str*/