/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/07 20:30:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Pipex tiene que crear un pipe y dos procesos hijos con fork, que el padre 
 * espere a que los dos hijos terminen su trabajo y devulve el exit_code del 
 * ultimo proceso en terminar
 */
int	ft_pipex(t_struct *st)
{
	int	exit_code;

	return (exit_code);
}

/**
 Un nuevo argumento para main -> @param env
	@param env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env
	//TODO en main -> inicializar la struct, comenzar pipex, retornar exit_code
	//! protecciones de los argumentos y gestión de errores (mejorar)
*/
int	main(int ac, char **av, char **env)
{
	t_struct	st;
	int			exit_code;

	if (ac < 5)
		return (1);
	if (!env || !*env)
		return (1);
	st = init_struct(ac, av, env);
	exit_code = ft_pipex(&st);
	return (exit_code);
}
