/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/19 11:25:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función asigna memoria y devuelve una array de strings terminados en '\0'
que se genera a partir de una string que recibe como parámetro
Esa cadena origen la queremos separar en otras cadenas (palabras), split tiene
que encontrar y separar cada palabra, dejando de lado el caracter dado por 
el parámetro char c*/

#include "libft.h"

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

/*Qué hace cont_word = un ciclo con tres "checks" dentro:
while(recorrer toda la cadena original *s)
	while(si lo que hay en cada posicion de str == c, seguimos i++)
	if(terminado el while de arriba, porque str != c, aumentamos cntr+ 1 vez)
	while(si no ha terminado str y s[i] es distinto a c, seguimos i++)
Así ya tenemos el número de strings que va a tener nuestra tabla resultado*/

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

/*Qué hace saveword = guardar como char* cada palabra que ft_split "encuentra"
Asigna memoria para el nuevo string con malloc y tamaño de n, que también ha 
calculado y enviado ft_split
Usa strncpy para copiar la cadena que llega desde ft_split hasta la posicion n
y así crea la nueva, solo con las posiciones de la original que nos interesa
Cómo = fr_split usa 3 contadores que nos dicen en que posicion de la original, 
hasta que posicion copiar y en que posicion de la tabla nueva colocar esto*/
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

/*Why tab[k] = NULL y no '\0'?? porque la posicion de tab no es un char, 
sino otra cadena de chars, así que cerramos la cadena de cadena con NULL*/