/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:18:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*Esta función recice una cadena y le da valor 0 a N bytes, es decir, una forma 
de crear una cadena de N tamaño en la que cada byte tendrá valor 0
usamos la función memset con valor 0 y le pasamos los mismo parámetros que recibe
la función principal bzero*/