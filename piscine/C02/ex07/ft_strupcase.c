/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:00:19 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/01 11:29:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
