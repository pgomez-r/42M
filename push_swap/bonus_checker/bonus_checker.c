/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:49:32 by pgruz             #+#    #+#             */
/*   Updated: 2023/02/18 13:57:29 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	main(int ac, char **av)
{
	char	**numbers;
	
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (write(2, "Error\n", 6), -1);	
}
