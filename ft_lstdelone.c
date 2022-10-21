/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:04:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/21 14:10:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}

/*Vamos a eliminar un nodo de la lista, para eso necesitamos no solo "romper"
los links de este nodo, para que no forme parte de la lista, sino también 
liberar el espacio que está ocupando actualmente*/
/*WTF función del "(*del)(void *)""
Le pasamos la función (*del) a a los datos (CONTENT), esto "saca" ese nodo de 
nuestra lista, luego para terminar aplicamos la función free a lst para liberar
la memoria que estaba usando el nodo*/