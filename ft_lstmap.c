/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:49:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/21 20:09:30 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	mapped;
	t_list	aux;

	if (!lst)
		return (NULL);
	mapped = ft_sltnew(f(lst->content));
	if (!mapped)
		return (NULL);
	aux = mapped;
	
	
	mapped->next = NULL;
	return (mapped);
}

/*lstmap crea una t_list nueva, resultado de aplicar la función f al contenido
de cada nodo de una t_list original que entra como parámetro, es decir, lstiter
pero generando una lista nueva resultado de modificar con f cada content
Metemos como siempre el if para comprobar si los parametros que recibe estan ok
Creamos dos variables t_list, una para la lista final que va a devolver lstmap y 
otra para que sirva de auxiliar para poder ir moviendo los nodos(como lstclear)

*/