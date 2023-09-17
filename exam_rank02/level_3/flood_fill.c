/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:15:18 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/30 19:10:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

/*flood_fill rellena con F todos los caracteres que sean iguales al inicial
mientras estén unidos por un camino válido, es decir, si el punto de partida
corresponde a 'C', comprueba todos los posibles alrededor de este, si son 'C'
los cambia por F, si no, comprueba otra dirección, cuando no encuentre más
'C' en ninguna dirección, la función termina*/

void	fill(char **tab, t_point size, t_point begin, char c)
{
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y
		|| begin.x >= size.x || tab[begin.y][begin.x] != c)
		return ;
	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point){begin.x, begin.y - 1}, c);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, c);
	fill(tab, size, (t_point){begin.x - 1, begin.y}, c);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, c);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/*Esta es la función que vuelve a "escribir" el mapa que hemos definido
en main, pero alojando memoria primero para la matriz de cadenas y luego
para cada cadena de la matriz, al final devuelve el mapa en char** */

// char	**map_maker(char **dstr, t_point size)
// {
// 	int		i;
// 	int		j;
// 	char	**map;

// 	map = malloc(sizeof(char *) * size.y);
// 	i = 0;
// 	while (i < size.y)
// 	{
// 		map[i] = malloc(sizeof(char) * (size.x + 1));
// 		j = -1;
// 		while (++j < size.x)
// 			map[i][j] = dstr[i][j];
// 		map[i][j] = '\0';
// 		i++;
// 	}
// 	return (map);
// }

/*En el main declaramos dos estructuras con y/x para las medidas del
mapa y las coordenadas de inicio, "escribimos" el mapa y lo alojamos
con una función (para evitar problemas de bus/memoria) Esto es para
preparar los elementos que usa flood_fill, luego para comprobar el 
resultado -> imprimimos primero el mapa normal, ejecutamos flood_fill
e imprimos el mapa de nuevo*/

// int	main(void)
// {
// 	t_point		size = {8, 5};
// 	t_point		begin = {1, 1};
// 	char 		*zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};
// 	char		**map;
// 	int			i;

// 	map = map_maker(zone, size);
// 	i = -1;
// 	while (map[++i])
// 		printf("%s\n", map[i]);
// 	printf("\n");
// 	flood_fill(map, size, begin);
// 	i = -1;
// 	while (map[++i])
// 		printf("%s\n", map[i]);
// 	printf("\n");
// 	return (0);
// }
