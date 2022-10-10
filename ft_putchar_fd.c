/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/10 09:23:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*Envía el caracter c al file descriptor especificado, igual que putchar 
o write, pero en luga de (1, &c, 1), 
usamos el int fd para que se sustituya por c*/