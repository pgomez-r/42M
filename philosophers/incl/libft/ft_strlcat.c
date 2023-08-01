/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:20 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 08:48:08 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	cont;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	cont = len_dst;
	while (*src != '\0' && cont < (size - 1))
	{
		*(dest + cont) = *src;
		cont++;
		src++;
	}	
	*(dest + cont) = '\0';
	return (len_dst + len_src);
}

/*Esta función concatena 2 strings hasta un límite (size) de caracteres,
copia la cadena src empezando desde el final del dest, pero la longitud
límite total se cuenta entre ambas cadenas, (desde la pos 0 de dest) 
es decir, que realmente lo que hace es contar los caracteres de dest
primero, copiar los que  falten para llegar al size - 1 y en ese último
caracter escribirá el final de línea.
Aunque la función concatena las dos cadenas, el valor que devuelve no es
la nueva cadena, sino un size_t con el valor del tamaño de esta.
Calculamos el valor del tamaño de cada cadena (con strlen), comprobamos
antes de nada con un if si el limite size pasado a la función es menor o
igual que el tamaño de dest, si se cumple significa que no se podrían
concatenar completamente las cadenas porque no habría "espacio", o que si
se pudisese sería justo del mismo tamaño que src + size, así que devol-
vemos len_src + size
En el resto de casos, bucle que se repite mientras la cadena src no termine
y cont (len de dest) no llegue a size - 1. En este bucle ponemos un puntero
en la posicion final de dest (con cont) y uno al principio de src, cada rep
copiamos en *dest + cont el valor de *src*/