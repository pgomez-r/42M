/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:36:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/19 16:47:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*Esta función añade a una lista un nuevo link (new) -que recibe como parámetro-
a un lista y lo coloca a la cabeza de la lista... lst en el prototipo es head
Lo que hacemos es mover *lst (la cabeza de lista) a la posicion siguiente del
nuevo link (new->next) y a la posición cabeza de lista le asignamos new 
(*lst=new)*/