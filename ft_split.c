/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/11 18:05:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*La función asigna memoria y devuelve una array de strings terminados en '\0'
que se genera a partir de una string que recibe como parámetro
Esa cadena origen la queremos separar en palabras, en otras cadenas, split tiene
que econtrar y separar cada palabra, dejando de lado los espacios y caracteres 
especiales
La vamos a dividir, 1º un contador para saber cuantas palabras (cadenas) 
tenemos que meter en el array final que devuelve la función*/

int	cont_word(char const *s, char c)
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

/*Qué hace el contador = un ciclo con tres "checks" dentro
while(recorrer toda la cadena original *s)
	while(si lo que hay en cada posicion de str == c, seguimos i++)
	if(terminado el while de arriba, porque str != c, aumentamos cntr+ 1 vez)
	while(si no ha terminado str y s[i] es distinto a c, seguimos i++)*/

/*OK, ya tenemos el número de strings que va a tener nuestra tabla resultado
Ahora, */
char	**ft_split(char const *s, char c)
{
	
}
