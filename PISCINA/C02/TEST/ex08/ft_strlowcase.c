/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:00:39 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/30 19:05:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*writer;

	writer = str;
	while (*writer != '\0')
	{
		if (*writer >= 'A' && *writer <= 'Z')
		{
			*writer = *writer + 32;
		}
		writer++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "Hola_Mundo_42";

	printf("Cadena:%s\n", str);
	ft_strlowcase(str);
	printf("Cadena nueva:%s\n", str);
}
