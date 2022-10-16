/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pruebas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:13:51 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/16 15:55:41 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	int	cont;
// 	int	num_char;

// 	cont = 0;
// 	num_char = 0;
// 	while (str[cont] != '\0')
// 	{
// 		num_char++;
// 		cont++;
// 	}
// 	return (num_char);
// }

// void	*ft_calloc(size_t n, size_t size)
// {
// 	char	*array;
// 	size_t	i;

// 	array = ((char *)malloc(n * size));
// 	i = 0;
// 	if (array == 0)
// 		return (0);
// 	while (i < n * size)
// 	{
// 		array[i] = 0;
// 		i++;
// 	}
// 	return ((void *)array);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*str;

// 	if (start > ft_strlen(s))
// 		return (ft_calloc(1, 1));
// 	if (len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	str = (char *)ft_calloc(sizeof(*s), (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		str[i] = s[start + i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// int	main(void)
// {
// 	char *str = "01234";
//  	size_t size = 10;
// 	printf("%s\n", ft_substr(str, 10, size));
// 	printf("%s\n", ft_substr(str, 10, size));
// 	return (0);
// }
