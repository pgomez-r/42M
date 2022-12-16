/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_draft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/16 20:44:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

*int	ft_atoi(char *arg, int *array)
{
	int		sig;
	int		num;

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
	return (num * sig);
}

int	main(void)
{
	char	*arg;
	int		array[5];
	int		i;

	arg = "1 2 3 4 5";
	array = ft_atoi(arg, array);
	i = 0;
	while (i < 5)
	{
		printf("%d", array[i]);
		i++;
	}
}
