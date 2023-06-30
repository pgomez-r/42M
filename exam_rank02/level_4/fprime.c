/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:11:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/30 19:49:58 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*PROGRAMA(incluye main) -> se permite uso de printf y atoi */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	num;
	int	i;

	if (ac != 2)
		return (printf("\n"), 0);
	num = atoi(av[1]);
	if (num == 1)
		return (printf("1\n"), 0);
	i = 1;
	while (num >= ++i)
	{
		
	}
	return (0);
}
