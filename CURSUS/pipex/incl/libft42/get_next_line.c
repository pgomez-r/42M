/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/21 09:38:15 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cuando llamamos a create_line, nuestra estática ya tiene todo lo que read ha
leido, según el buffer que tuviese asignado puede haber más de un '\n'. Vamos 
a copiar todo el contenido de la estática en line, hasta que encontremos un '\n'
Primero comprobamos que tanto la estática como su contenido no sean nulas
Luego usamos un contador a 0 y un bucle hasta '\n' o '\0' para calcular el tamaño
que necesita line, al salir del bucle comprueba si el siguiente char es '\n', si
es así aumenta una vez más el contador (hay que incluir ese '\n' en line)
Asignamos memoría para line de tamaño i + 1 (para '\0'), reiniciamos i a 0 para
usarlo de nuevo como índice
Hacemos mismo bucle que antes pero copiando en cada ejecución line[i]=stack[i],
también comprobamos el caso de que el char después del bucle sea '\n' y cerramos
cadena con '\0' antes de return (line)
*/

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*Cuando llamamos a update_stack yqa hemos conseguido con create_line
la línea que vamos a devolver al terminar la función GNL, pero justo
antes de eso, con esta función, vamos a hacer que en nuestra estática
solo se queden el resto de caracteres leidos DESPUÉS de esa línea
Usamos una cadena auxiliar, como hacemos en free_and_join, para así 
poder liberar la memoria asignada anteriormente justo antes de devolver
el nuevo valor que va a tener la estática 
(aux = resto de stack, free stack y luego stack = aux)*/

/*Para movernos por stack, declaramos un puntero nuevo, lo apuntamos
a la posición de la estática dondé está '\n' (usando strchr) y lo aumentamos
p++ más "saltar" ese '\n'
Luego asignamos memoria para aux calculando el len de la cadena estática desde
la posición del puntero (strlen(p) +1 para '\0') y luego copiamos el contenido
de stack en aux, de nuevo usando nuestro puntero que ya sabemos que está en
la posición de stack justo después de '\n', cuando termine ese while, cerramos
cadena, liberamos stack y devolvemos aux, que en la función principal dará
el nuevo valor a stack (stack = update_stack) */

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

	p = ft_strchr(stack, '\n');
	if (!p)
	{
		free (stack);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (*p != '\0')
	{
		aux[i] = *p;
		i++;
		p++;
	}
	aux[i] = '\0';
	free (stack);
	return (aux);
}

/*la idea de join_and_free es poder hacer tanto el strjoin para añadir el último
buffer leído a la estática, como también poder liberar la memoria asignada antes
a nuestra estática
para eso usamos una cadena auxiliar, a esta le asignamos strjoin de stack y tmp,
en ese momento aux pasa a tener el contenido que queremos que tenga stack,
liberamos stack, devolvemos aux y en GNL tenemos que stack = join_and_free, es
decir, stack = aux
IMPORTANTE: "iniciamos" la estática aquí, cuando le vamos a añadir caracteres
leidos por primera vez, con un if, así solo lo hará la primera llamada de GNL,
ya que en los demás casos ya estará inicializada y tendrá contenido*/

char	*join_and_free(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = 0;
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	free (stack);
	return (aux);
}

/*Desde main se envía un file descriptor a GNL, en esta declaramos las variables
para una cadena estática, una cadena temporal para que read guarde los caracteres
que lea, un entero para igualarlo siempre al número de char leidos por read y una
cadena "line" que será que devolvamos finalmente
La idea global es ir guardando todo lo leido en la estática, hasta que detectemos
que ya contiene al menos un '\n', en ese momento usamos dos funciones auxiliares,
una para guardar hasta '\n' en la cadena char line que devuelve la función y otra
para actualizar el contenido de nuestra estática, borrando justo esa línea que ya
hemos devuelto, así en la siguiente llamada a GNL, no volverá a encontrarse ni 
devolver esa linea*/

/*Para guardar lo leido en stack, hacemos que read guarde en tmp todo lo que lea
y luego hacemos un join de stack + tmp. Antes de cada lectura comprobamos que
stack no tenga todavía ningun '\n', si es así, dejamos de leer y usamos las dos 
funciones auxiliares, mientras no sea el caso, seguimos leyendo y haciendo join
*/

/*El bucle para realizar lecturas se ejecuta hasta que se encuentre '\n' en 
stack o hasta que no se hayan leido más caracteres (fin de archivo), para poder
iniciar el bucle tenemos que asignar valor >0 a readbytes primero. También es 
importante terminar cada tmp con '\0' y comprobar que se haya podido "actulizar"
correctamente stack con el join*/

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!(ft_strchr(stack, '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[readbytes] = '\0';
		stack = join_and_free(stack, tmp);
		if (!stack)
			return (NULL);
	}
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}

/*Comprobaciones: 1)si fd o buffer size son nulos/erroneo, return NULL
	2)si read da fallo (<0) free stack y return NULL
	3)si el resultado de join stack y tmp es nulo, return NULL*/