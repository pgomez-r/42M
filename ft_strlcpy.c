/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/05 13:00:18 by pgomez-r         ###   ########.fr       */
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
