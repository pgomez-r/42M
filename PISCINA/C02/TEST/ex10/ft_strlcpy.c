/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/01 11:14:26 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	cnt;

	cnt = 0;
	while (src[cnt] != '\0')
	{
		if (cnt < size)
		{
			dest[cnt] = src[cnt];
		}	
		cnt++;
	}
	printf("Dest: %s\n", dest);
	return (cnt);
}

int	main(void)
{
	char	dest[50];
	char	*src;
	unsigned int	size;
	int	total_length;
	
	src = "Hola_Mundo_42";
	size = 6;
	total_length = ft_strlcpy(dest, src, size);
	printf("Long: %d", total_length);
}
