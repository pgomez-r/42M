/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:28:21 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/21 19:18:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*aux_link;

	if (!lst || !del)
		return ;
	aux = *lst;
	aux_link = *lst;
	while (aux)
	{
		aux_link = aux_link->next;
		ft_lstdelone(aux, del);
		aux = aux_link;
	}
	*lst = 0;
}

/*Esta función hace lo mismo que lstdelone, borra un nodo, pero además 
también borra todos los nodos que le siguen. La idea es llamar a lstdelone
1 vez para cada nodo en un bucle. Para movernos de nodo a nodo, mejor dicho, 
mover cada nodo en la cadena, creamos 2 VARIABLES TLIST que sirven de auxiliares
Primero, asignamos a ambos aux el puntero a *lst, ahora mismo los dos tienen el 
mismo nodo
Empezamos un while donde: a aux2 le asignemos el nodo al que apunta su next
(el siguiente nodo), habiendo "guardado" ese nodo en aux2, borramos aux1 llamando
a la funcion lstdelone,ahora le damos a aux1 (vacio) el valor de aux_link = como 
ya esta "vacio", le "metemos" el siguiente nodo, comienza de nuevo el while.*/