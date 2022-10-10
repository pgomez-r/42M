/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/06 12:14:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, void *src, int n)
{
	char	*dest_cpy;
	char	*src_cpy;
	int		i;

	if (dest == NULL)
		return (NULL);
	dest_cpy = (char *) dest;
	src_cpy = (char *) src;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest_cpy);
}

/* En ejemplo del compi, src es CONST, n es SIZE_T, 
y los _cpy son unsigned char (src UNSIGNED CONST)/*