/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:59:34 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/20 22:06:44 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief imprime matrices de cadenas de caracteres(char **) separadas por salto
 * de línea
 */
void	ft_print_dstr(char **dstr)
{
	size_t	i;

	i = 0;
	while (dstr[i] != NULL)
	{
		ft_printf("%s\n", dstr[i]);
		i++;
	}
}
