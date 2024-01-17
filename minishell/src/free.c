/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:24:28 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/15 22:36:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Archivo para funciones de final de programa y liberación de memoria*/

#include "../inc/minishell.h"

/*Se llama antes de cada readline; en la primera ocasión inicia valores a 0
En el resto además libera las variables que han necesitado malloc en la lectura
anterior*/
void	ft_clean_input(t_input *input)
{
	ft_free_cmds(input);
	ft_free_arr(input, input->n_elements);
	input->cmd_n = 0;
	input->n_elements = 0;
	free(input->pipes);
	input->pipes = NULL;
	if (access(".heredoc", F_OK) == 0)
		remove(".heredoc");
}
/**
 * TODO: Check si se están liberando en exeguttor los char** de cms
 * Tendrían que liberarse y dejar a NULL cada vez que se termina una exe,
 * para luego volver a hacerles malloc y darles valor si es necesario en
 * siguientes comandos
 */

/*Función para liberar memoria de la struct inicial-general, que
ahora mismo solo tiene el entorno duplicado*/
void	ft_free_data(t_data *d)
{
	size_t	i;

	i = -1;
	while (++i < ft_strdlen(d->env_dup))
	{
		free(d->env_arr[i].full);
		free(d->env_arr[i].title);
		free(d->env_arr[i].line);
	}
	free(d->env_arr);
}

void	ft_free_cmds(t_input *in)
{
	int	i;

	i = -1;
	while (++i < in->cmd_n)
	{
		if (in->cmds[i].path_cmd != NULL)
			free(in->cmds[i].path_cmd);
		if (in->cmds[i].cmd_line != NULL)
		{
			free(in->cmds[i].cmd_line);
			in->cmds[i].cmd_line = NULL;
		}
		if (in->cmds[i].paths != NULL)
			ft_totalfree(in->cmds[i].paths);
		if (in->cmds[i].cmd_tab != NULL)
			ft_totalfree(in->cmds[i].cmd_tab);
		free(in->cmds[i].tokens);
	}
}
/**
 * TODO: check si se le está haciendo malloc siempre a todas las vars
 * TODO: pensar trigger IF para activar la función y en que momentos
 * El último free seguramente de doble free!
 */

void	ft_free_arr(t_input *in, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(in->elements[i].data);
		in->elements[i].data = NULL;
	}
}

/*Función para liberar toda la memoría alojada cuando se haga exit del
programa*/
void	ft_clean_exit(t_data *d)
{
	if (&d->in.n_elements > 0)
		ft_clean_input(&d->in);
	if (d->rl_input != NULL)
		free(d->rl_input);
	free(d->in.cmds);
	free(d->in.elements);
	ft_free_data(d);
}
/**
 * TODO: mejorar el IF (comprobación) para liberar o no
 */
