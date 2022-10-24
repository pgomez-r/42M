/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:44:23 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/24 16:49:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta función recibe un entero (neg o pos) y lo devuelve representado
en una cadena char
Vamos a usar dos funciones aux, una para calcular cuantos bytes necesitará
la cadena nueva, la otra para "escribir" byte a byte en formato char cada
digito del número int*/

#include "libft.h"

int	ft_byte_ctr(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (ft_byte_ctr(n * (-1)) + 1);
	else if (n < 10)
		return (1);
	else
		return (ft_byte_ctr(n / 10) + 1);
}

/*Esta función calcula el número de bytes (espacios) que va a necesitar 
la cadena final que devolverá ft_itoa y lo asigna como valor a int size
Si el entero es el valor mínimo int: return 11; si es negativo: la función se 
llama a sí misma con (n * -1) + 1; si es menor de 10, return 1 
En cualquier otro caso, se llama así misma con division (n / 10) + 1
La manera en la que calcula el numero total es aumentando + 1 en cada llamada
recursiva que hace así misma -excepto en el caso del número mínimo-
Ej: el entero son 5 dígitos, la función se llama así misma 4 veces y cuando
solo queda el 1er digito, se cumple else if n < 10, return 1 (valor inicial), 
ahora termina de hacer todos los return pendientes, cada uno sumando + 1
1 + 4 = 5 digitos, en el caso de n negativo, la primera llamada a si misma 
también suma + 1 sin haber hecho todavía la div n/10 que "recorta" el número,
ya que en cadena char vamos a necesitar tambien 1 byte para representar el signo
*/

void	ft_write_str(char *str, int size, long int num)
{
	str[size] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		while (size > 1)
		{
			str[size - 1] = num % 10 + '0';
			num = num / 10;
			size--;
		}
	}
	else
	{
		while (size > 0)
		{
			str[size - 1] = num % 10 + '0';
			num = num / 10;
			size--;
		}
	}
}

/*Esta función va a "escribir" el número en una cadena vacía, desde itoa
le enviamos la cadena str, size (numero de bytes, calculados antes) y el
numero int incial (por medio de la variable long int num = n)
Lo primero que hacemos es escribir el fin de linea '\0' en str usando la
posicion de size, luego hacemos dos supuestos, si es negativo o positivo
si es negativo, antes de nada, str[0] = '-' y num = num *-1, luego ambos
casos se desarrollan igual: rellenamos cada byte, empezando por el ultimo
con el módulo %10 de num convertida a char (+'0') y seguimos "descomponiendo"
el numero entero con divisiones por 10
En el caso de número negativo, hacemos el bucle hasta la posicion de cadena
size > 1 , porque la posicion [0] ya tiene el signo negativo '-', en caso de 
positivo: while size > 0.
Para movernos dsde el final, nos vamos a size - 1 (-1 porque el espacio
final ya tiene '\0') */

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	num;

	size = ft_byte_ctr(n);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	num = (long int)n;
	ft_write_str(str, size, num);
	return (str);
}

/*Con las dos funciones auxiliares operativas, qué hace la función principal: 
	1. Declarar y dar valor al tamaño que tendrá la cadena char final, esto 
	lo hacemos llamando a la funcion contador.
	2. Crear una cadena char vacía, reservando memoria con calloc (malloc puede
	que funcione también, no estoy seguro) de size + 1 para luego cerrarla con '0'
	3. Pasamos el número que le entra a la función como int n a un long int para
	proteger el supuesto de que entre un número demasiado grande, lo hacemos creando
	una variable long int y asignandole valor de n casteado (long int)n
	4. Llamar a la función que "escribe" el número, con todos pasandole todos los 
	parámetros anteriores
	5. Devolvemos la cadena y le preguntanmos a Paco a ver cómo lo ve
	*/