/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:05:26 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/05 12:53:56 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		sig;
	int		num;

	sig = 0;
	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	while ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sig++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		num = (*str - '0') + (num * 10);
		str++;
	}
	if (sig % 2 != 0)
		sig = -1;
	if (sig % 2 == 0)
		sig = 1;
	num = num * sig;
	return (num);
}
