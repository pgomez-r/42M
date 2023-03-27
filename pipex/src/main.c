/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/27 23:08:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

/*Un nuevo argumento para main -> @**env
	@env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env*/
int	main(int ac, char **av, char **env)
{
	t_struct	st;
	size_t		i;

	atexit(ft_leaks);
	(void)ac;
	(void)av;
	get_paths(&st, env);
	st.cmd = "ls";
	find_path(&st);
	if (!st.match_path)
		return (printf("PATH O CMD NO VALIDOS:\n"), ft_totalfree(st.paths), 1);
	printf("PATH ENCONTRADO:\n%s\n", st.match_path);
	i = 0;
	// while (st.paths[i] != NULL)
	// 	printf("%s\n", st.paths[i++]);
	ft_totalfree(st.paths);
	return (0);
}

/*Vamos a sacar de **env la línea PATH y guardar todas sus direcciones
en nuestra variable @**char	paths*/
void	get_paths(t_struct *st, char **env)
{
	int		i;
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
	i = -1;
	while (st->paths[i++])
		st->paths[i] = (join_and_free(st->paths[i], "/"));
}

int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}

/*Ya tenemos los paths de env en una variable, esta función tiene que
encontrar el MATCH entre el comando a ejecutar y su correspondiente path*/
void	find_path(t_struct *st)
{
	size_t	i;

	if (!st->match_path)
		st->match_path = NULL;
	i = 0;
	while (!st->paths[i])
	{
		st->match_path = ft_strjoin(st->paths[i], st->cmd);
		if (access(st->match_path, F_OK | X_OK) == 0)
			return ;
		free(st->match_path);
		i++;
	}
}	
