/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:11:57 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/28 21:02:36 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief comprueba al final del programa si se han producido memory_leaks
 * se entrega el proyecto sin usarla para no alterar el output final
 * HOWTO -> añadir en función main como "atexit(ft_leaks)" para usarla 
 * 			y cambiar aquí el nombre del ejecutable
 */
void	ft_leaks(void)
{
	system("leaks -q so_long");
}
