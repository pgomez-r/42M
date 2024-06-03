/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:29:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/20 13:23:28 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ctr;

	ctr = 0;
	while (lst)
	{
		lst = lst->next;
		ctr++;
	}
	return (ctr);
}

/*Esta función devuelve el número de nodos que tiene una lista, hacemos un bucle
para recorrer la lista, mientras el nodo (lst) no se nulo, lo vamos "moviendo"
hacia adelante (lst = lst->next) y por cada vez que hagamos esto, aumentamos el
contador, que es lo que devolvemos finalmente*/