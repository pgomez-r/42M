/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:00:39 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/01 11:29:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
