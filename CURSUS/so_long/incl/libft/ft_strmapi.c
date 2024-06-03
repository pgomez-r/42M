/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 09:07:36 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*Esta función aplica la función f dada como parámetro a cada caracter de la 
string s y genera una nueva string con el resultado, es el mismo funcionamiento
que en strteri, pero copiando el resultado de cada "repeticion" a una nueva str
Primero creamos y reservamos memoria para la cadena nueva, luego comenzamos el
mismo while que en strteri, pero al mismo tiempo, str[i] tendrá el valor 
resultante de la función f... str[i] = f(i, s[i]), al final cerramos cadena y 
la devolvemos*/