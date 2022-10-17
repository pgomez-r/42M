/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:21 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/17 14:32:57 by pgomez-r         ###   ########.fr       */
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

/* busca un string corto (nd) en otro más grande (hs), si
 * encuentra la coincidencia devuelve el puntero al principio de la coincidencia
 * */