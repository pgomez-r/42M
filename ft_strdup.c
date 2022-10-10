/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/07 11:03:48 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *src)
{
	char	*dup;

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
 * un puntero al string, si no hay suficiente memoria devuelve 0
 Me falta hacer que funcione llamando a malloc y que retorne 0 si dup == 0*/