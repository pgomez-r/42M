/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:22 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 18:04:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*la función putendl añade un salto de línea a una cadena char, en el caso de
putendl_fd, además tiene en cuenta el filedescriptor para escribir tanto la
cadena como el salto de linea
para llevarla a cabo usamos putstr y putchar, ambos usando el file descriptor,
es decir: "imprimir" cadena + "imprimir char" ambos usando fd*/