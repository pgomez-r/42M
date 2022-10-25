/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pruebas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:57:00 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:04:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_lst;
// 	t_list	*aux;
// 	/*dos variables t_list, para ir moviendo y guardando de una a otra los 
// 	nodos de lst después de aplicarles función f*/
// 	if (!lst || !f)
// 		return (NULL);
// 	/*comprobamos que la lista no sea nula/vacía, si lo es, abortamos mision*/
// 	new_lst = ft_lstnew(f(lst->content));
// 	if (!new_lst)
// 		return (NULL);
// 	/*creamos un nuevo nodo a partir de aplicar la funcion f al contenido de 
// 	lst (primer nodo), + un if por si no se ha podido crear el nuevo nodo, 
// 	abortamos mision*/
// 	aux = new_lst;
// 	/*"guardamos" en aux el nodo new_lst*/
// 	while (lst)
// 	{
// 		if (lst->next)
// 		{
// 			/*si NO es el último nodo de la lista*/
// 			new_lst->next = ft_lstnew(f(lst->next->content));
// 			/*creamos un nuevo nodo para el siguiente nodo de new_lst, 
// 			a partir de aplicar la funcion f al contenido del nodo actual 
//			de lst*/
// 			if (!(new_lst->next))
// 			{
// 				ft_lstclear(&new_lst, del);
// 				return (NULL);
// 			}
// 			new_lst = new_lst->next;
// 		}
// 		lst = lst->next;
// 		/*cada ciclo termina "desplazando" al siguiente nodo de la lista*/
// 	}
// 	new_lst->next = (NULL);
// 	/*termina ciclo while porque estamos en el ultimo nodo, le asignamos
// 	a su next = NULL para "cerrar cadena"*/
// 	return (aux);
// 	/*why return el aux en lugar de new_lst? aux es igual que lst, no se le ha
// 	aplicado funcion f a sus nodos, no entiendo*/
// }

/*lstmap devuelve una t_list* que es resultado de aplicar función f al contenido
de cada nodo de una t_list* original que entra como parámetro, es decir, lstiter
pero generando una lista nueva resultado de modificar con f cada content*/