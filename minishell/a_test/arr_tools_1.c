/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:59:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*Para catalogar los nuevos elementos resultantes de la división del 
original, solo sirve dentro de ft_arr_update (de momento)*/
void	ft_tag_type(t_element *arr, int start, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(arr[start].data, c))
			arr[start++].type = c;
		else
			arr[start++].type = '0';
		i++;
	}
}

/*Cataloga los elementos nuevos despues de dividir por << / >> */
void	ft_tag_redtype(t_element *arr, int start, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(arr[start].data, c))
		{
			if (c == '<')
				arr[start++].type = 'h';
			else if (c == '>')
				arr[start++].type = 'a';
		}
		else
			arr[start++].type = '0';
		i++;
	}
}

/*Para guardar el elemento separador de ft_element_split en su
propia cadena, que devolvemos para insertar en la posición de la
matriz de cadenas correspondiente*/
char	*ft_write_token(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

/*Mismo que ft_write_token, guarda el elemento separador de
dbred_split en su propia cadena, que se inserta en la posición que
le corresponde dentro de la matriz de cadenas*/
char	*ft_save_dbred(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 3);
	str[0] = c;
	str[1] = c;
	str[2] = '\0';
	return (str);
}

/*Versión equivalente al count_words de nuestro ft_split estandar
pero teniendo en cuenta que el elemento separador tiene su propia
cadena*/
size_t	ft_count_elements(char *str, char c)
{
	int		i;
	size_t	cnt;

	i = -1;
	cnt = 1;
	while (str[++i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			cnt++;
		if (str[i + 1] != '\0')
			cnt++;
	}
	return (cnt);
}
