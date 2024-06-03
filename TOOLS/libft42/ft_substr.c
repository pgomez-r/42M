/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:33:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:55:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)ft_calloc(sizeof(*s), (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*Esta función designa memoria y devuelve una cadena nueva que es
una copia de una porción de la cadena dada en el prototipo
La porción a copiar será desde la posición de la cadena que marque start
y tantos bytes siguientes como sea el valor de len

Comprobamos si el punto de inicio se sale de la cadena (si start es mayor
que strlen de s), en ese caso devolvemos memoria vacia con calloc(1,1)
Comprobamos si la longitud solicitada para la copia es mayor que el tamaño
de la cadena s, en ese caso: cambiamos el valor de len a strlen(s) menos start
Creamos un contador i y un char * para la nueva cadena y le asignamos memoria
con CALLOC, de tamaño len + 1 (para el '\0' de final de cadena) + if por si no
se ha podido reservar la memoria abortar misión
Luego es solo crear un bucle para ir copiando desde start hasta len, mientras 
el contador sea menor que len, copiamos a str y seguimos aumentando i*/