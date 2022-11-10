/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/05 15:27:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
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
