/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:44:00 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/26 22:00:44 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typedef struct s_lis_utils
// {
// 	int		*array_len;
// 	int		*array_index;
// 	int		*lis;
// 	size_t	lis_len;
// }			t_lis_utils;

void	lis_len_index(int *array, t_lis_utils *utils, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		utils->array_len[i] = 1;
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && utils->array_len[j] + 1
				>= utils->array_len[i])
			{	
				utils->array_len[i] = utils->array_len[j] + 1;
				utils->array_index[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*generate_lis(int *array, t_lis_utils *utils, size_t size)
{
	int	i;
	int	j;

	utils->lis_len = ft_max_in_array(utils->array_len, size);
	utils->lis = malloc(sizeof(int) * utils->lis_len);
	i = size - 1;
	while (utils->array_len[i] != (int)utils->lis_len)
		i--;
	j = utils->lis_len - 1;
	while (j >= 0)
	{	
		utils->lis[j] = array[i];
		i = utils->array_index[i];
		j--;
	}
	return (utils->lis);
}

int	*ft_lis(int *array, size_t size, size_t *size_lis)
{
	t_lis_utils	utils;

	utils.array_len = malloc(sizeof(int) * size);
	utils.array_index = malloc(sizeof(int) * size);
	lis_len_index(array, &utils, size);
	utils.lis = generate_lis(array, &utils, size);
	(*size_lis) = utils.lis_len;
	return (free(utils.array_index), free(utils.array_len), utils.lis);
}
