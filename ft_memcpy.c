/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 14:54:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_cpy;
	unsigned const char		*src_cpy;
	size_t					i;

	dest_cpy = (unsigned char *) dest;
	src_cpy = (unsigned char *) src;
	i = 0;
	if (!dest_cpy || !src_cpy)
		return (NULL);
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest_cpy);
}

/* En ejemplo del compi, src es CONST, n es SIZE_T, 
y los _cpy son unsigned char (src UNSIGNED CONST)*/