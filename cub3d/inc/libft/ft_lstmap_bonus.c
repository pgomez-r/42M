/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:49:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:04:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*lstmap devuelve una t_list* que es resultado de aplicar función f al contenido
de cada nodo de una t_list* original que entra como parámetro, es decir, lstiter
pero generando una lista nueva resultado de modificar con f cada content*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	aux = new_lst;
	while (lst)
	{
		if (lst->next)
		{
			new_lst->next = ft_lstnew(f(lst->next->content));
			if (!(new_lst->next))
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			new_lst = new_lst->next;
		}
		lst = lst->next;
	}
	new_lst->next = (NULL);
	return (aux);
}

/*
creamos dos variables t_list*, en new vamos a guardar los nodos de 
lst después de aplicarles función f, aux = new antes de empezar ciclo

comprobamos que los parámetros de entrada son correctos, sino, abortamos

"iniciamos" la lista new_lst = creamos un nuevo nodo a partir de aplicar la 
funcion f al contenido de lst (primer nodo de lst), + un if por si no se ha 
podido crear el nuevo nodo, en ese caso abortamos mision

aux = new; aux va a apuntar a new en su posicion inicial, antes de
desplzar el puntero por los diferentes nodos de la lista (creo que es la idea)

comenzamos un ciclo que se repite mientras lst no sea nulo, en cada rep
lo que hacemos es: 
	1.apuntamos al nodo siguiente de new (new_lst->next), le asignamos un nodo
	creado con lstnew a partir de aplicar f al contenido del nodo siguiente de
	lst en su posicion actual (lst->next->content)
		2.si no se consigue generar este nuevo nodo, lstclear de la direccion 
		de memoria de new:lst, del y abortamos, esto se comprueba con cada nodo
	3.apuntamos al siguiente nodo de la lista new (new_lst = new_lst->next)
	4.apuntamos al siguiente nodo de la lista original (lst = lst->next)

cuando termina el ciclo, hemos pasado y modificado todos los nodos de la 
original a la nueva, solo falta "cerrar" la lista asignando null al último nodo

return aux, en lugar de new_lst... porque aux apunta a la posicion inicial,porque
así lo asignamos antes de comenzar a "movernos" por lst y new, así devolvemos la
lista apuntando a su head
*/
