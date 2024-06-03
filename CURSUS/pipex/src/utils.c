/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:57:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/21 20:44:44 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	free_cache(t_command *st, int error)
{
	if (st)
	{
		if (st->paths != NULL)
			ft_totalfree(st->paths);
		if (st->cmd != NULL)
			ft_totalfree(st->cmd);
	}
	if (error > 0)
		exit(error);
}

/**
 * Abrimos los archivos y guardamos su fd nuestras dos variables, prefiero
 * tenerlo en struct que en dos enteros o array de enteros en main
 *  */

void	ft_openfiles(t_struct *d, char **av, int i)
{
	d->fd_in = open(av[1], O_RDONLY);
	if (d->fd_in == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), av[1]);
		exit(EXIT_FAILURE);
	}
	d->fd_out = open(av[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->fd_out == -1)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), av[i]);
		exit(EXIT_FAILURE);
	}
}
