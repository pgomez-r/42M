/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:23:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:55:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
}

/*En el if comprobamos que la lista lst no esté vacia, si lo está, simplemente
*lst = new, lo que haría que new sea el primer y último nodo de la lista, hacemos
return para que no continue la función después de este punto
Si no es así, creamos una variable t_list *, le declaramos como valor ft_lstlast 
de lst, por lo que aux = ultimo nodo de lst, luego decimos que el link(next)
de ese ultimo nodo es igual a new, así, el ultimo link de la lista apunta
al nuevo nodo, que pasa a ser el último de la lista*/