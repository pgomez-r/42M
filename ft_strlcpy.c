/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 16:42:38 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cnt;

	cnt = 0;
	if (size > 0)
	{	
		while (src[cnt] && cnt < (size - 1))
		{
			dest[cnt] = src [cnt];
			cnt++;
		}
		dest[cnt] = '\0';
	}
	while (src[cnt])
		cnt++;
	return (cnt);
}
