/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:42:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/20 22:44:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*La función asigna memoria y devuelve una array de strings terminados en '\0'
que se genera a partir de una string que recibe como parámetro
Esa cadena origen la queremos separar en otras cadenas (palabras), split tiene
que econtrar y separar cada palabra
Palabra = "una parte de la cadena delimitada por espacios o por el principio
o final de cadena"
	"espacios" == ' ', '\t', '\n'*/

/*Primero hay que calcular cuantas cadenas (palabras) vamos guardar en la matriz
de cadenas, lo hacemos con un bucle con tres "checks" dentro:
while(recorrer toda la cadena original *str)
	while(si lo que hay en cada posicion de str == espacios, seguimos i++)
	if(terminado el while de arriba, porque str != espacios, aumentamos len 1 vez
		porque sabemos que ya hemos encontrado una palabra)
	while(si no ha terminado str (fin de cadena) y s[i] es distinto a "espacios", 
		seguimos i++, para seguir hasta "salir" de la palabra y volver a saltar
		espacios hasta la siguiente o fin de cadena)
Así ya tenemos el número de strings que va a tener nuestra tabla resultado*/

/*Repetimos un bucle muy parecido al de contar las palabras, pero en este cuando
encontramos una palabra (str[i] != espacios) fijamos un indice j en ese punto
Luego continuamos desplazando i hasta salir de la palabra y en ese momento 
tenemos la longitud de la cadena que va a guardar esa palabra (sizeof i - j + 1)
Alojamos memoria y guardamos en la matriz tab[k][len] cada caracter moviendonos
con otro iterador (yo reciclo len que usamos antes) tantas veces como i-j; 
luego cerramos la ultima posicion de tab[k][len] con fin de cadena '\0', 
aumentamos el iterador de posicion de tab[k] y repetimos hasta se termine str
Por último, cerrar la matriz de cadenas con tab[k] == NULL y return (tab)*/
