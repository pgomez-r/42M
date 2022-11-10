/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:01:26 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:16 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr = *ptr + 32;
		ptr++;
	}
	ptr = str;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (*ptr != '\0')
	{
		if ((*ptr >= 32 && *ptr <= 47) || (*ptr >= 58 && *ptr <= 64)
			|| (*ptr >= 91 && *ptr <= 96) || (*ptr >= 123 && *ptr <= 255))
		{
			ptr++;
			if (*ptr >= 'a' && *ptr <= 'z')
				*ptr = *ptr - 32;
		}
		else
			ptr++;
	}
	return (str);
}

int main(void)
{
	char str[] = "salut cAmmnt,,,,,tu vAs ? 42mots quAra|nte-deux; cinquAnte+et+un";

	printf("ORIGEN: %s\n", str);
	ft_strcapitalize(str);
	printf("NUEVA:  %s\n", str);
}
