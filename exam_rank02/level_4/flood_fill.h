/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:15:18 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/30 18:59:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Necesitamos definir una estructura para definir luego las medidas/coordenadas
que usaremos en flood_fill, las librerías stdio y stdlib no nos harían falta, 
están incluidas para poder probar el main con printf y malloc*/

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

#endif