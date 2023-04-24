/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:57:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/24 21:28:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Cierra los fd "creados" al hacer open del archivo de entrada y el de salida
 * la usamos a la hora de terminar el programa para no dejar ningun fd en uso
 */
void	close_fds(t_struct *st)
{
	if (st->fd_in != -1)
		close(st->fd_in);
	if (st->fd_out != -1)
		close(st->fd_out);
}

/**
 * Cierra los dos extremos (fd's) del pipe que hemos generado anteriormente, hay 
 * que cerrar el pipe en cada proceso para que no nos de fallo en parent/main
 */
void	close_pipe(t_struct *st)
{
	close(st->pipe[0]);
	close(st->pipe[1]);
}

/**
 * Función para terminar el programa, comprueba variables de struct que pueden
 * necesitar ser liberadas (strings y arrays), si están inicializadas las libera
 * @param error = al llamar a la función le enviamos un 1 en caso de que estemos
 * terminando el programa por haberse producido un error -> entonces la función 
 * ejecuta exit con EXIT_FAILURE 
 * Si recibe 0 no ejecuta exit, ya lo hará con normalidad nuestro main al final
 */
void	exit_pipex(t_struct *st, int error)
{
	if (st)
	{
		close_fds(st);
		if (st->pipe != NULL)
			free(st->pipe);
		if (st->paths != NULL)
			ft_totalfree(st->paths);
		if (st->cmd1 != NULL)
			ft_totalfree(st->cmd1);
		if (st->cmd2 != NULL)
			ft_totalfree(st->cmd2);
	}
	if (error > 0)
		exit(EXIT_FAILURE);
}
