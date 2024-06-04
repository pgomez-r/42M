/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:05:42 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/28 15:02:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
	{
		printf("cascaribash: malloc error\n");
		exit(EXIT_FAILURE);
	}
	return (alloc);
}
