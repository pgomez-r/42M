/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:21 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/07 11:28:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *hs, const char *nd, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*nd)
		return (*hs);
	i = 0;
	while ((hs[i] != '\0') && (i < n))
	{
		j = 0;
		if (hs[i] == nd[j])
		{
			while ((nd[j] == hs[i + j]) && (i + j < len))
			{
				if (nd[j + 1] == '\0')
					return ((char *)hs + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/* busca un string corto (nd) en otro más grande (hs), si
 * encuentra la coincidencia devuelve el puntero al principio de la coincidencia
 * */