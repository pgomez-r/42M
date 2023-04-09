/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:18:41 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/08 17:48:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Esta función guarda los datos que vamos a usar en pipex, desde ac, av,
 * env, etc - muchas lineas para hacerlo en main, así que lo hace esta y devuelve
 * un struct que se iguala a la declarada en main
 * En nuestra struct @param st queremos almacenar todas las variables que vamos a
 * ir usando, incluso los argumentos del main ac, av, env...así será mucho más 
 * cómodo todo el proceso
 * TODO -> Función aux que ponga todos los valores a 0/NULL antes de nada
 */
t_struct	init_struct(int ac, char **av, char **env)
{
	t_struct	st;

	st = set_st_empty();
	st.ac = ac;
	st.av = av;
	st.env = env;
	get_paths(&st);
	commands_parser(&st);
	return (st);
}

/**
 * Deja cada elemento de la estructura "vacío" antes de comenzar a darle valores
 * char = NULL, int = -1 -> (porque 0 podría ser un fd o PID válido) 
 */
t_struct	set_st_empty(void)
{
	t_struct	st;

	st.ac = -1;
	st.av = NULL;
	st.env = NULL;
	st.paths = NULL;
	st.path_cmd = NULL;
	st.cmd1 = NULL;
	st.cmd2 = NULL;
	st.cmd_opt = NULL;
	st.fd_in = -1;
	st.fd_out = -1;
	st.pipe = NULL;
	st.pids = NULL;
	st.pid = -1;
	return (st);
}

/**
 * Crea un pipe (dos fd) para cada comando
 */
void	pipe_gen(t_struct *st)
{
	if (st->pipe == NULL)
		st->pipe = malloc(sizeof(int) * 2);
	if (pipe(st->pipe) == -1)
		exit_pipex(st);
}
