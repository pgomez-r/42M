/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:14:31 by pgruz             #+#    #+#             */
/*   Updated: 2022/12/30 12:43:08 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			sig;
	long int	num;

	sig = 1;
	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	if (ft_isdigit((int) *str) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{	
		num = (*str - '0') + (num * 10);
		str++;
	}
	num = num * sig;
	// if (num > INT_MAX || num < INT_MIN)
	// 	num = NULL;
	return (num);
}

int	main(void)
{
	const char	*input_num;
	long int	output_num;

	input_num = "-214748364890";
	output_num = ft_atoi(input_num);
	if (output_num < INT_MIN || output_num > INT_MAX)
		return (printf("Error"), -1);
	printf("Output_num:%ld\n", output_num);
}
