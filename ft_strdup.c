/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 10:22:21 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*dup;
	unsigned int	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (*src != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i + 1] = '\0';
	return (dup);
}

/*Esta función aloja suficiente memoria para copiar s1, hace la copia y devuelve
 * un puntero al string, si no hay suficiente memoria devuelve 0*/