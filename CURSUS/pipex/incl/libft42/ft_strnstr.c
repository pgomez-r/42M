/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:21 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:35:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*nd)
		return ((char *)hs);
	i = 0;
	while (hs[i] != '\0' && i < n)
	{
		j = 0;
		while (i + j < n && hs[i + j] == nd[j] && nd[j] != '\0')
			j++;
		if (nd[j] == '\0')
			return ((char *)hs + i);
		i++;
	}
	return (NULL);
}

/*Busca un string corto (nd) en otro más grande (hs), el hs se recorre n
número de caracteres y si se encuentra una coincidencia con nd, devuelve un
puntero a la posicion de hs donde empieza esta coincidencia, casteado a char*
para cumplir con el man de strnstr.
Si no entra un nd válido como parámetro a strnstr, se devuelve puntero a hs
en su primera posición.
Hacemos un bucle para recorrer y comparar hs y nd con dos contadores, i va a 
aumentar y recorrer hs, hasta que el valor de la pos actual de hs sea igual que
el valor de la posición inicial de nd (hs[i + j] == nd[j]) en ese momento, j
comienza a aumentar mientras i queda "parado", hasta que llegue llegue al fin de
cadena de nd, en ese momento se devuelve un puntero char a hs desplazado a la pos
que marque i ((char*)hs + i)
para que esto pase y se retorne un puntero a hs, tiene que coincidir la cadena
nd al completo con hs desde la primera coincidencia, hasta fin de candea de nd
si no, se saldría del segundo while, se continuaría aumentando i en el primer 
while y, en caso de que no vuelva a coincidir y se termine hs sin coincidencia
se devuelve NULL*/