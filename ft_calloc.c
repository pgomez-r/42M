/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:42:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/10 09:07:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	int	*array;
	int	i;

	array = ((char *)malloc(n * size));
	i = 0;
	if (array == 0)
		return (0);
	while (i < n * size)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}

/*Esta función aloja de forma contigua espacio para count objetos que son size 
 * bytes de memoria y devuelve un puntero a la memoria alojada, esta memoria se
 * llena con bytes de valor 0*/