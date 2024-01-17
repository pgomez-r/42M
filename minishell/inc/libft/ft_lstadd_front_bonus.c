/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:36:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:59:29 by pgomez-r         ###   ########.fr       */
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

/*Esta función añade a una lista un nuevo nodo -que recibe como parámetro-
y lo coloca a la cabeza de la lista
Lo que hacemos es mover *lst (la cabeza de lista) a la posicion siguiente del
nuevo link (new->next) y a la posición cabeza de lista le asignamos new 
(*lst=new)*/