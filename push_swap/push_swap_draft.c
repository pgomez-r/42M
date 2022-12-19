/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_draft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/19 15:10:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy_free(char *dest, char *src)
{
	// char	*aux;
	int		cnt;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	// free(dest);
	return (dest);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_checkargs(char **numbers)
{
	int	i;
	int	j;

	if (!*numbers || !**numbers)
		return (0);
	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[i][j] != '\0')
		{
			if (numbers[i][j] == '-')
				j++;
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);
}

int	ft_count_word(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	return (count);
}

char	*ft_savewords(const char *s, unsigned int n)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * ((ft_count_word(s, c)) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{	
			tab[k] = ft_savewords(s + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

void	ft_leaks(void)
{
	system("leaks -q test");
}

int	main(int ac, char **av)
{
	char	**numbers;
	int		i;

	atexit(ft_leaks);
	if (ac <= 1)
		return (printf("Sin argumentos, taluego"), -1);
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	if (ac > 2)
	{
		i = 0;
		numbers = malloc(sizeof(char *) * ac);
		while (av[i + 1])
		{
			numbers[i] = ft_strcpy_free(numbers[i], av[i + 1]);
			i++;
		}
		numbers[i] = NULL;
	}
	i = 0;
	while (numbers[i])
	{	
		printf ("%s ", numbers[i]);
		i++;
	}
	if (!ft_checkargs(numbers))
		return (printf("Argumentos erróneos, taluego"), -1);
	return (0);
}
