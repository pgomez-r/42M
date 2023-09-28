/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:59:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/28 20:20:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		aux;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (nbr == 0)
		return ("0\0");
	aux = nbr;
	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	nbr = aux;
	str[i] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr)
	{
		str[--i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/*Para convertir el número entero que recibe la función en una cadena char,
lo primero que necesitamos es saber que tamaño va a tener esta cadena
Usamos un auxiliar para guardar el valor real de nbr, luego empezamos a
descomponerlo en dígitos dividiendolo por 10 y sumando +1 al tamaño de la
cadena cada vez (check primero si el número es negativo para aumentarlo tabmbién
ya que necesitamos espacio en la cadena para el signo '-')
Cuando ya tenemos el tamaño, alojamos memoria, devolvemos nbr a su valor original
y comenzamos a descomponerlo /10 de nuevo, esta vez guardando el módulo en cada
posición de str (desde el final) en formato char -> + '0'
De nuevo, hay que comprobar antes de hacer esto si nbr es negativo, en ese caso
posición incial de la cadena = '-' */

int	main(int ac, char **av)
{
	int	nbr;

	if (ac != 2)
		return (printf("Error de argumentos\n"), 1);
	nbr = atoi(av[1]);
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
