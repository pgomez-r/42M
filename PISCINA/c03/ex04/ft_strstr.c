/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:45:28 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/05 10:06:52 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *find)
{
	int	a;
	int	b;

	if (*find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *find)
		{
			a = 0;
			b = 0;
			while (find[a] != '\0')
			{
				if (str[a] != find[a])
					b = 1;
				a++;
			}
			if (b == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
