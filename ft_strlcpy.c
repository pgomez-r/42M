/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 10:29:48 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	cnt;

	cnt = 0;
	while (src[cnt] != '\0')
	{
		if (cnt < size)
		{
			dest[cnt] = src[cnt];
		}	
		cnt++;
	}
	return (cnt);
}
