/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:19:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/09/26 13:05:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		sign;
	int		num;

	sign = 0;
	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 12))
		str++;
	while ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		num = (*str - '0') + (num * 10);
		str++;
	}
	if (sign % 2 != 0)
		sign = -1;
	if (sign % 2 == 0)
		sign = 1;
	num = num * sign;
	return (num);
}
