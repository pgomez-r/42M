/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pruebas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:10:47 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/17 14:34:12 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	*ft_strnstr(const char *hs, const char *nd, size_t n)
// {
// 	size_t	i;
// 	size_t	j;

// 	if (!nd)
// 		return ((char *)hs);
// 	i = 0;
// 	while (hs[i] != '\0' && i <= n)
// 	{
// 		j = 0;
// 		while (i + j < n && hs[i + j] == nd[j] && nd[j] != '\0')
// 			j++;
// 		if (nd[j] == '\0')
// 			return ((char *)hs + i);
// 		i++;
// 	}
// 	return (NULL);
// }

// int	main(void)
// {
// 	char *s1 = "oh no not the empty string !";
//  	char *s2 = "";
// 	size_t max = strlen(s1);
// 	printf("%s\n", strnstr(s1, s2, max));
// 	printf("%s\n", ft_strnstr(s1, s2, max));
// 	return (0);
// }
