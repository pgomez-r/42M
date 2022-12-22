/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_draft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/22 13:42:51 by pgomez-r         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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

int	ft_atoi(const char *str)
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

void	ft_totalfree(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{	
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

int	ft_checkduplicates(char **str)
{
	int	i;
	int	j;
	int	ctr;

	i = 0;
	while (i < (int)ft_strlen((const char *)str))
	{
		j = 0;
		ctr = 0;
		while (j < (int)ft_strlen((const char *)str))
		{	
			if (!ft_strcmp(str[i], str[j]))
				ctr++;
			j++;
		}
		if (ctr > 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_leaks(void)
{
	system("leaks -q test");
}

int	main(int ac, char **av)
{
	char			**numbers;
	unsigned long	i;
	int				*array;

	atexit(ft_leaks);
	if (ac <= 1)
		return (printf("Sin argumentos, taluego"), -1);
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	if (ac > 2)
	{
		i = 0;
		numbers = malloc(sizeof(char *) * ac);
		if (!numbers)
			return (-1);
		while (av[i + 1])
		{
			numbers[i] = ft_strcpy(numbers[i], av[i + 1]);
			i++;
		}
		numbers[i] = NULL;
	}
	//PROBLEMA si entran 4 argumentos, pero uno es una cadena con numeros entre "
	//qué hacemos? ej: "4 2 5 6" 4 8 esto creo que se lo traga y no debería
	if (!ft_checkargs(numbers))
		return (ft_totalfree(numbers), printf("Argumentos erróneos"), -1);
	if (ft_checkduplicates(numbers))
		return (ft_totalfree(numbers), printf("Argumentos erróneos"), -1);
	//y otro ft_checkmin_max (o quizás se pueda comprobar en ft_atoi modificado)
	i = 0;
	while (numbers[i])
		i++;
	array = malloc(sizeof(int) * i);
	i = 0;
	while (numbers[i])
	{
		array[i] = ft_atoi(numbers[i]);
		i++;
	}
	//aquí hay que comprobar si el array está ordenado
	// if (ft_sortcheck)
	// 	return (printf("Números ya se han enviado ordenados, taluego"), -1);
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < sizeof(array))
		printf ("%d ", array[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array);
	return (0);
}

