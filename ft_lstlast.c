/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:58:30 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/19 17:12:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*fwrd;

	if (!lst)
		return (0);
	fwrd = lst->next;
	while (fwrd)
	{
		lst = fwrd;
		fwrd = lst->next;
	}
	return (lst);
}
