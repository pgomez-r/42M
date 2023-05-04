/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:58:30 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 17:15:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (0);
	aux = lst->next;
	while (aux)
	{
		lst = aux;
		aux = lst->next;
	}
	return (lst);
}
/*Devuelve el puntero de t_list lst (que entra como parámentro) situado en el
último nodo ("posicion") de la lista
Lo que hacemos es crear un nuevo t_list * que usamos como auxiliar para ir 
"desplazando" el puntero de lst hasta el último nodo
Empezamos asignandole a aux la posicion a la que apunta el next de lst, luego
iniciamos un bucle en el que primero damos lst el valor de aux y luego a aux el
del siguiente nodo de lst, así nos vamos "desplazando" hasta que aux sea nulo
en ese caso lst ya está apuntando a su ultimo nodo, entonces la devolvemos*/