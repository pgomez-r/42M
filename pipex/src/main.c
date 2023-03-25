/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 23:12:38 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/*Un nuevo argumento para main -> @**env
	@env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env*/
int	main(int ac, char **av, char **env)
{
	t_struct	tools;
	size_t		i;

	ft_paths(&tools, env);
	(void)ac;
	(void)av;
	i = 0;
	while (tools.paths[i] != NULL)
		printf("%s\n", tools.paths[i++]);
	return (0);
}

/*Vamos a sacar de **env la línea PATH y guardar todas sus direcciones
en nuestra variable @**char	paths*/
void	ft_paths(t_struct *tools, char **env)
{
	size_t	i;

	i = 0;
	while (env[i] && is_path(env[i]))
		i++;
	tools->paths = ft_split(env[i], ':');
}

int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}
