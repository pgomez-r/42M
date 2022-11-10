/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:00:19 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/30 19:04:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*writer;

	writer = str;
	while (*writer != '\0')
	{
		if (*writer >= 'a' && *writer <= 'z')
		{
			*writer = *writer - 32;
		}
		writer++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "Hola_Mundo_42";

	printf("Cadena:%s\n", str);
	ft_strupcase(str);
	printf("Cadena nueva:%s\n", str);
}
