/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:23:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/15 18:51:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Lista de comproboaciones según subject.pdf
 * - Extensión .brew
 * - Char permitido: 0, 1, C, E, P, X
 * - Exit y Player una unidad cada
 * - Medidas rectangulares (x > y)
 * - Mapa rodeado de '1'
 * - Camino válido (floodfill)
 */

/*Check .brew y que solo haya chars permitidos y un solo P y E*/
void	check_format(t_struct *st)
{

}

/*Check si rectangular y si rodeado de 1*/
void	check_shape(t_struct *st)
{

}

/*El famoso floodfill o floorfill*/
void	check_wayout(t_struct *st)
{

}
