/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/01 00:56:26 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/*Un nuevo argumento para main -> @**env
	@env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env*/
int	main(int ac, char **av, char **env)
{
	t_struct	st;
	char *options[3] = {"ls", "-la", NULL};

	st.pid = fork();
	if(st.pid == -1)
		return (1);
	atexit(ft_leaks);
	(void)ac;
	(void)av;
	get_paths(&st, env);
	st.cmd = "ls";
	find_path_index(&st);
	if (!st.match_path)
		return (printf("PATH O CMD NO VALIDOS!\n"), ft_totalfree(st.paths), 1);
	printf("PATH ENCONTRADO:\n%s\n", st.match_path);
	execve(st.match_path, options, env);
	printf("OK!");
	return (ft_totalfree(st.paths), free (st.match_path), 0);
}

/*Vamos a sacar de **env la línea PATH y guardar todas sus direcciones
en nuestra variable @**char	paths*/
void	get_paths(t_struct *st, char **env)
{
	size_t	i;
	char	*fix;

	i = 0;
	fix = NULL;
	while (env[i] && is_path(env[i]))
		i++;
	st->paths = ft_split(env[i], ':');
	fix = ft_strcpy(fix, st->paths[0] + 5);
	free(st->paths[0]);
	st->paths[0] = ft_strcpy(st->paths[0], fix);
	free(fix);
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->paths[i] = (join_and_free(st->paths[i], "/"));
		i++;
	}
}

/*Ya tenemos los paths de env en una variable, esta función tiene que
encontrar el MATCH entre el comando a ejecutar y su correspondiente path*/
int	find_path_index(t_struct *st)
{
	int	i;

	if (!st->match_path)
		st->match_path = NULL;
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->match_path = ft_strjoin(st->paths[i], st->cmd);
		if (access(st->match_path, F_OK | X_OK) == 0)
			return (i);
		free(st->match_path);
		i++;
	}
	return (-1);
}	
