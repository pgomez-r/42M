/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/25 08:20:53 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*Esta función aplica la función f a cada caracter de s, usando como parámetros 
el indice de cada caracter y su dirección: f(unsigned int i, char* s + i);
Creamos un contador, unsigned int para que concuerde con el del prototipo de
la función f y un bucle que recorre toda la cadena s, en cada repetición aplica
la función f, que recibe como parámetros el contador y el caracter al que apunta
el puntero de la cadena s, que vamos a ir desplazando al pasarlo como (s + i)
*/