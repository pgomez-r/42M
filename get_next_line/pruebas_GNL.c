/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_GNL.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:54:32 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/28 13:50:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char		*linea;

// 	if (fd < 0 || BUFF_SIZE < 0)
// 		return (NULL);
// 	read (fd, linea, BUFF_SIZE);
// 	return (linea);
// }

// /*
// Quiero guardar todo el texto en una tabla de strings, un array 2d
// */

int	main(void)
{
	int		fd;
	char	linea[1000];
	int		i;
	int		aux;

	fd = open("sometext.txt", O_RDONLY);
	i = 0;
	aux = -1;
	while (aux != i)
	{
		aux = i;
		i += (int)read(fd, (linea + i), BUFF_SIZE);
		// printf("Reserva:%s\n", linea);
	}
	printf("Texto en archivo:\n%s", linea);
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	// aux = i;
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	// i += (int)read(fd, (linea + i), BUFF_SIZE);
	// printf("Reserva:%s\n", linea);
	return (0);
}

/*Desde main abrimos el archivo y asignamos su file descriptor a fd para
mandarlo luego a GNL
Declaramos tambien una cadena char para que contenga cada linea que nos
devuelva GNL
Hacemos un bucle infinito para llamar repetidamente a GNL, despuúes de cada
ejecución de esta función hacemos print de linea para comprobar, y free de linea
para liberar ese espacio antes de usar de nuevo la función, cerramos el bucle
con un break cuando la linea que devuelva GNL sea nula*/