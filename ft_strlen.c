/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:59:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/10 12:38:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	cont;
	int	num_char;

	cont = 0;
	num_char = 0;
	while (str[cont] != '\0')
	{
		num_char++;
		cont++;
	}
	return (num_char);
}
