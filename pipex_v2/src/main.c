/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/16 20:55:29 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Abrir archivo infile, que entra al programa desde consola como av[1]
 * usamos ft_print + strerror para poder incluir en el output del error el
 * nombre del archivo que no se ha podido abrir/encontrar
 * Protegemos el posible error al abrir archivo, ya sea por falta de
 * permisos o que no exista, si su fd es -1 imprimimos streerror y el nombre
 * del archivo que ha dado el fallo
 * dup() para colocar los fd como nos interesa, en este caso hacemos que
 * el fd de infile sea stdinput y el fd del extremo de nuestro pipe sea
 * stdout, así el comando que ejecutamos toma con input nuestro archivo y
 * "guarda" su resultado (output) en el extremo de nuestro pipe que luego
 * comunicará y servirá como input en el segundo comando (me explico fatal)
 * Buscamos la ruta que necesita el comando a ejectuar y luego llamamos a
 * excve con esa ruta(path_cm), el comando y sus opciones (cmd) y la variable
 * de entorno (env) y protegemos el posible error con exit_pipex
 * WHY print_error -> para imprimir por salida de errores, con mensaje command
 * not found y referencia a la variable enviada, así imitamos el mensaje que
 * mostaría zsh en este tipo de error
 */
void	child_proc(t_struct	*st)
{
	st->fd_in = open(st->av[1], O_RDONLY);
	if (st->fd_in == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), st->av[1]);
		exit(EXIT_FAILURE);
	}
	dup2(st->fd_in, STDIN_FILENO);
	dup2(st->pipe[1], STDOUT_FILENO);
	close_pipe(st);
	find_path_index(st, st->cmd1[0]);
	if (execve(st->path_cmd, st->cmd1, st->env) == -1)
	{
		ft_printf_error("pipex: command not found: %s\n", st->cmd1[0]);
		exit(127);
	}
}

/**
 * mismo procedimiento que en child_proc, pero en este caso abirmos/creamos 
 * el archivo outfile (son solo nombres, puedes llamarlos file_a, file_b...)
 * si no existe lo creamos y si existe lo "sobreescribimos" (TRUNC)
 * dup() para que el extremo de nuestro pipe sea el stdinput (ya que ahí hemos
 * "guardado" antes el output del primer comando) y que el fd del archivo que
 * hemos abierto sea equivalente al stdout -> lo que vamos a ver finalmente en
 * consola
 */
void	parent_proc(t_struct *st)
{
	st->fd_out = open(st->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (st->fd_out == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), st->av[4]);
		exit(EXIT_FAILURE);
	}
	dup2(st->pipe[0], STDIN_FILENO);
	dup2(st->fd_out, STDOUT_FILENO);
	close_pipe(st);
	find_path_index(st, st->cmd2[0]);
	if (execve(st->path_cmd, st->cmd2, st->env) == -1)
	{
		ft_printf_error("pipex: command not found: %s\n", st->cmd2[0]);
		exit(127);
	}
}

/**
 * ft_pipex genera un pipe para que "comunique" el output del primer comando
 * al segundo comando, que lo tomará como input
 * fork() genera procesos nuevos dentro del mismo programa -> lo usamos dos veces
 * para crear dos procesos (uno para cada comando a ejecutar)
 * dup() intercambia file descriptors del sistema, nos permite hacer que el fd de
 * un archivo que hemos abierto pase a ser el fd 0 de standard input, por ejemplo
 * creamos los dos procesos y hacemos que pipex espere a que terminen (y que el
 * segundo espere al primero a su vez, para asegurarnos que nunca se cierre el 
 * programa quedando algun proceso sin terminar)
 * cada proceso ejecuta cada comando que entra por consola, usando excve()
 */
void	ft_pipex(t_struct *st)
{
	pipe_gen(st);
	st->pid_child = fork();
	if (st->pid_child == -1)
	{
		perror("pipex: fork failed");
		exit_pipex(st, 1);
	}
	else if (st->pid_child == 0)
		child_proc(st);
	else
	{
		st->pid_child = fork();
		if (st->pid_child == -1)
		{
			perror("pipex: fork failed");
			exit_pipex(st, 1);
		}
		else if (st->pid_child == 0)
			parent_proc(st);
		else
			close_pipe(st);
	}
	waitpid(st->pid_child, NULL, 0);
}

void	ft_openfiles(int *fd, char **av, int i)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), av[1]);
		exit(EXIT_FAILURE);
	}
	fd[1] = open(av[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), av[i]);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	cmd_n;

	cmd_n = 3;
	if (ac < 5)
		return (perror("Error: wrong number of arguments\n"), 1);
	if (!env || !*env)
		return (perror("pipex: env parse error"), 1);
	ft_openfiles(fd, av, ac - 1);
	ft_pipex(av[2], env, fd[0]); //cambiar prototipo para que reciba sin struct;
	while (cmd_n < ac - 2)
		ft_pipex(av[cmd_n++], env, 1);
	system("leaks -q pipex");
	return (0);
}
