/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/07 10:46:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if ((unsigned char *)(str1[i]) != (unsigned char *)(str2[i]))
			return ((unsigned char *)(str1[i]) - (unsigned char *)(str2[i]));
		i++;
		return (0);
	}
}

/*Esta función compara la información en memoria byte por byte y si hay alguna
 *diferencia la devolverá, si no devolverá 0*/