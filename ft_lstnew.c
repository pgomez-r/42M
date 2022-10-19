/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:23:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/19 15:04:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* lstnew == CREAR UN NODO */

/*Vamos a usar esta función para crear un nodo nuevo con el contenido que
le enviemos, es decir, devolvemos una variable t_list a la que se ha añadido
como cabeza el content que le pasamos a lstnew al llamarla*/

/*Para hacerlo, creamos una variable tipo puntero a t_list -que es la que vamos
a devolver cuando termine la función- y le asignamos memoria con malloc sizeof
tlist (+ if check si se ha podido asignar)
Ahora, a new le damos como elemento a t_list new (nuenewo nuevo nodo) lo que
le envian a la funcion como *content */
