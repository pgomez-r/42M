/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:19:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/21 19:46:38 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

/*
lstiter toma la funcion f que entra por parámetros y la aplica al contenido
de cada nodo de la lista, es decir, tenemos que hacer un bucle para aplicar f a 
cada lst->content, while lst->NEXT no sea nulo (para saber cuando llegamos al
último nodo), primero f(lst->content) y luego asignamos a lst el nodo al que 
apunta su puntero next; cuando se cumple while estamos en el último nodo, asíque
aplicamos f al contenido de este nodo por ultima vez antes de terminar la función
*/