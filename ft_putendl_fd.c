/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:22 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/13 13:26:45 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*La función escribe el string que entra como parámetro char *s 
en el file descriptor fd seguido de \n para hacer un salto de linea
es como putendl, que simplemente añade el salto de linea a un str, pero usando fd
para llevarla a cabo usamos dos funciones anteriores: putstr_fd + putchar_fd
es decir: "imprimir" cadena + "imprimir char" ambos usando fd*/