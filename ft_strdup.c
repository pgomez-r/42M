/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/13 09:35:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (*src != '\0')
	{
		*dup = *src;
		src++;
		dup++;
	}
	*dup + 1 = '\0';
	return (dup);
}

/*Esta función aloja suficiente memoria para copiar s1, hace la copia y devuelve
 * un puntero al string, si no hay suficiente memoria devuelve 0*/