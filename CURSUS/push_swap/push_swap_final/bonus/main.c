/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/27 20:41:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] == s1[i] && i < n -1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	easy_free(t_index *index, char **numbers)
{
	ft_totalfree(numbers);
	free (index->array_a);
	free (index->array_b);
}

int	chose_op(t_index *index, char *ops)
{
	if (!ft_strncmp(ops, "sa\n", 3))
		return (swap_a(index), 0);
	else if (!ft_strncmp(ops, "sb\n", 3))
		return (swap_b(index), 0);
	else if (!ft_strncmp(ops, "ss\n", 3))
		return (swap_ab(index), 0);
	else if (!ft_strncmp(ops, "pa\n", 3))
		return (push_a(index), 0);
	else if (!ft_strncmp(ops, "pb\n", 3))
		return (push_b(index), 0);
	else if (!ft_strncmp(ops, "ra\n", 3))
		return (rotate_a(index), 0);
	else if (!ft_strncmp(ops, "rb\n", 3))
		return (rotate_b(index), 0);
	else if (!ft_strncmp(ops, "rr\n", 3))
		return (rotate_ab(index), 0);
	else if (!ft_strncmp(ops, "rra\n", 4))
		return (revrot_a(index), 0);
	else if (!ft_strncmp(ops, "rrb\n", 4))
		return (revrot_b(index), 0);
	else if (!ft_strncmp(ops, "rrr\n", 4))
		return (revrot_ab(index), 0);
	else
		return (write(2, "Error\n", 6), 1);
}

int	main(int ac, char **av)
{
	char	**numbers;
	char	*ops;
	t_index	index;

	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (1);
	if (ft_getarrays(numbers, &index))
		return (ft_totalfree(numbers), write(2, "Error\n", 6), 1);
	if (!ft_chkdup(&index))
		return (easy_free(&index, numbers), write(2, "Error\n", 6), 1);
	ops = get_next_line(0);
	while (ops)
	{
		index.flag = chose_op(&index, ops);
		free (ops);
		if (index.flag == 1)
			return (easy_free(&index, numbers), 1);
		ops = get_next_line(0);
	}
	if (!ft_chksort(&index) && index.size_b == 0)
		return (easy_free(&index, numbers), free(ops), write(1, "OK\n", 3), 0);
	return (easy_free(&index, numbers), free(ops), write(1, "KO\n", 3), 0);
}
