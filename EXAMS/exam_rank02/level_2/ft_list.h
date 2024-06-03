/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:27:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/14 08:30:23 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Archivo .h para incluir en todas las funciones de listas*/

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif
