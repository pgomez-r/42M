/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:18:41 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/16 18:51:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Esta función guarda los datos que vamos a usar en pipex, desde ac, av,
 * env, etc - y devuelve un struct que se iguala a la declarada en main
 * En @param st queremos almacenar todas las variables que vamos a usar después,
 * así será mucho más cómodo todo el proceso y ahorraremos líneas por función
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
 * Así también nos aseguramos de poder hacer todos los free en una sola función
 * para gestionar la memoria, ya que en esa función solo liberamos lo que sea 
 * diferente de NULL / -1
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
	st.fd_in = -1;
	st.fd_out = -1;
	st.pipe = NULL;
	st.pid_child = -1;
	st.error_flag = 0;
	return (st);
}

/**
 * Genera un pipe con dos extremos o finales -> un array de dos elementos 
 * -> dos fd que se relacionan o comunican entre ellos
 * Como ya tenemos en nuestra struct @param pipe[2], hacemos pipe(st->pipe)
 * y pipe[0] y pipe[1] se convierten en los dos extremos (fds) conectados
 */
void	pipe_gen(t_struct *st)
{
	if (st->pipe == NULL)
		st->pipe = malloc(sizeof(int) * 2);
	if (pipe(st->pipe) == -1)
	{
		perror("Pipe failed");
		exit_pipex(st, 1);
	}
}
