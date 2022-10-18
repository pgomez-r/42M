/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/18 10:55:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dest_cpy;
	const char		*src_cpy;
	size_t			i;

	dest_cpy = dest;
	src_cpy = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	char		*p;
// 	const char	*q;

// 	q = src;
// 	p = dest;
// 	if (dest == NULL && src == NULL)
// 		return (NULL);
// 	while (n > 0)
// 	{
// 		*p = *q;
// 		p++;
// 		q++;
// 		n--;
// 	}
// 	return (dest);
// }

/* En ejemplo del compi, src es CONST, n es SIZE_T, 
y los _cpy son unsigned char (src UNSIGNED CONST)*/