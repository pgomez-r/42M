/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:34:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/17 22:05:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*A ft_list_foreach le entra una función como segundo argumento,
y esta tenemos que aplicarla a un elemento (data) de cada nodo de 
la lista enlazada
Es un poco liosa la sintaxis (*f)(void *), pero simplificado es 
equivalante a "funcion(variable)" parece (*f) para indicar que
es cualquier funcion y (void *) como "comodin" para que pueda 
recibir cualquier tipo de variable
De nuevo, simplificando, tenemos que pensar que ft_list_foreach, 
a parte del puntero a la lista enlazada, recibe una función que 
vamos a pasarle a cada elemento data de la lista*/

/*A mi me pareció más lioso comprender la idea y la sintaxis que 
el código en si, ya que solo tenemos que recorrer la lista hasta 
que no se pueda más, y en cada repetición del bucle aplicamoa la
función al elemento data del nodo al que estamos */