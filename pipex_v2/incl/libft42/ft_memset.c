/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 17:54:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}

/*Escribe len bytes de valor c (casteados a unsigned char) en 
una cadena str, que es lo que devuelve la función
Se trata de hacer un bucle para que mientras el contador no alcance
el valor de n, se escriba en cad posicion de str el valor de c,
lo importante una vez más: castear siempre las variables de acuerdo
con lo que especifica man y el prototipo*/