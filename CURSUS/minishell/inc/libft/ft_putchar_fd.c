/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:17:23 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*Igual que ft_putchar, pero el write que va a llamar, en lugar de (1, &c, 1),
que solemos usar, a write le vamos a pasar como primer parámetro el valor de fd
el 1 que usamos normalmente es para standar output, con fd no especificamos que 
sea necesariamente ese output sino que puede variar segun el valor que le entre
a la función*/