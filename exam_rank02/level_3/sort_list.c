/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:42:17 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/29 13:36:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
Muy parecida a ft_list_remove_if, pero no necesitamos recursividad para esta
Vamos a usar la función cmp de nuevo, que le llega como argumento a sort_list,
pero esta vez devuelve 0 si los dos enteros que compara no están en orden 
ascendente, es decir, si hay que ordenarlos
*/

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*lst_start;
	int		aux;

	lst_start = lst;
	while (lst->next != NULL)
	{	
		if (cmp(lst->data, lst->next->data) == 0)
		{
			aux = lst->data;
			lst->data = lst->next->data;
			lst->next->data = aux;
			lst = lst_start;
		}
		else
			lst = lst->next;
	}
	lst = lst_start;
	return (lst);
}

/*
La solución también es parecida a la de list_remove_if, usamos un puntero
auxiliar que de primeras igualamos a lst, para tener siempre guardada el
inicio de la lista.
Hacemos un bucle que recorra la lista entera, hasta que no queden nodos
En este la función cmp compara el elemento data del nodo actual (lst->data) 
y del nodo siguiente (lst->next->data), si hay que ordenarlos (cmp == 0) 
usamos una variable int auxiliar para intercambiar los valores entre 
lst-data y lst-next-data (como nuestra ft_swap básica con punteros).
->	a aux le guardamos el valor de data del nodo actual, a este le damos 
	el valor de data del siguiente nodo y finalmente a ese data del 
	siguiente, el que guardamos primero en aux.
Después de hacer el swap, igualamos lst a lst-aux, para volver al incio de
la lista, y reiniciar el bucle al principio hasta que encontremos otros dos
nodos cuyos elementos data no estén ordenados, así finalmente tendremos 
toda la lista ordenada.
Antes de terminar, volvemos a igualar lst a lst_start para que la función
devuelva un puntero al primer elemento de la lista (lo que pide el subject)
*/