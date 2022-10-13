/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:39:14 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/13 14:03:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*str;
	unsigned char		ch;

	str = (unsigned char *)s;
	ch = (unsigned char *)c;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/* No etiendo por qué CONST VOID, yo intentaba const char */