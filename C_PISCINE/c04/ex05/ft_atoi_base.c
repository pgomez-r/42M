/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:19:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/05 17:57:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		num;
	char 	base;
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
		num = (*str - '0') + (num * base_size);
		str++;
	}
	if (sign % 2 != 0)
		sign = -1;
	if (sign % 2 == 0)
		sign = 1;
	num = num * sign;
	return (num);
}
