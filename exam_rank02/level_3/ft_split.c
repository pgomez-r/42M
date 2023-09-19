/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:42:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/19 19:27:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función asigna memoria y devuelve una array de strings terminados en '\0'
que se genera a partir de una string que recibe como parámetro
Esa cadena origen la queremos separar en otras cadenas (palabras), split tiene
que econtrar y separar cada palabra
Palabra = "una parte de la cadena delimitada por ESPACIO, TAB, '\' o por el
principio o final de cadena"*/

/*Qué hace count_word = un ciclo con tres "checks" dentro:
while(recorrer toda la cadena original *s)
	while(si lo que hay en cada posicion de str == c, seguimos i++)
	if(terminado el while de arriba, porque str != c, aumentamos cntr+ 1 vez)
	while(si no ha terminado str y s[i] es distinto a c, seguimos i++)
Así ya tenemos el número de strings que va a tener nuestra tabla resultado*/

/*Qué hace saveword = guardar como char* cada palabra que ft_split "encuentra"
Asigna memoria para el nuevo string con malloc y tamaño de n, que también ha 
calculado y enviado ft_split
Usa strncpy para copiar la cadena que llega desde ft_split hasta la posicion n
y así crea la nueva, solo con las posiciones de la original que nos interesa
Cómo = fr_split usa 3 contadores que nos dicen en que posicion de la original, 
hasta que posicion copiar y en que posicion de la tabla nueva colocar esto*/
char	**ft_split(char *str)
{
	int				i = 0;
	int				j = 0;
	int				k = 0;
	int				len = 1;
	char			**tab;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			len++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	tab = malloc(sizeof(char *) * len);
	if (!tab || !str)
		return (NULL);
	i = 0;
	len = -1;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
			i++;
		if (i > j)
		{	
			tab[k] = malloc(sizeof(char) * ((i - j) + 1));
			if (tab[k] == NULL)
				return (NULL);
			while (++len <= (i - j))
			{
				tab[k][len] = str[j];
				j++;
			}
			tab[k][len] = '\0';
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

/*Why tab[k] = NULL y no '\0'?? porque la posicion de tab no es un char, 
sino otra cadena de chars, así que cerramos la cadena de cadena con NULL*/