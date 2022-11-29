/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/29 14:12:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*cada vez que pull_line extrae una línea nueva, no necesitamos más esos chars,
así que esta función se encarga eliminarlos de nuestra pila para que solo 
queden los chars que vamos a seguir usando*/

void	update_stack()
{
	
}

/*extrae chars de la pila hasta encontrar un \n y los devuelve como *line*/

void	pull_line()
{
	
}

/*coloca la cadena de char obtenida por read_and_save al final de la pila
donde vamos a ir guardando todo el texto*/

void	move_to_stack()
{
	
}

/*usa read() para guardar chars en una cadena*/

void	read_and_save()
{
	
}

/*función principal, llama a todas las auxiliares necesarias y devuelve *line*/

char	*get_next_line(int fd)
{
	
}