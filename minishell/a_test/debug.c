/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:55:39 by pgruz11           #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_check_std(void)
{
	if (isatty(0))
		ft_printf("STDIN -> TERMINAL\n");
	else
		ft_printf("STDIN -> FILE\n");
	if (isatty(1))
		ft_printf("STDOUT -> TERMINAL\n");
	else
		ft_printf("STDOUT -> FILE\n");
}

void	debug_cmds(t_input *in, char *str_in, char *msg)
{
	int	i;
	int	j;

	printf("///INPUT_LINE\\\\\\\n%s\n\n", str_in);
	printf("///%s\\\\\\\n\n", msg);
	printf("Número comandos actual: %d\n", in->cmd_n);
	i = -1;
	while (++i < in->cmd_n)
	{
		j = -1;
		printf(" --- COMMAND[%d] --- \n", i);
		printf("CMD_LINE[%d]: %s\n", i, in->cmds[i].cmd_line);
		while (++j < in->cmds[i].size)
		{
			printf("Data elem[%d]: %s <---> ", j, in->cmds[i].tokens[j].data);
			printf("Type elem[%d]: %c\n", j, in->cmds[i].tokens[j].type);
		}
	}
}

void	debug_arr(t_input *in, char *str_in, char *msg)
{
	int	i;

	printf("///INPUT_LINE\\\\\\\n%s\n\n", str_in);
	printf("///%s\\\\\\\n\n", msg);
	printf("Número elementos actual: %d\n", in->n_elements);
	i = -1;
	while (++i < in->n_elements)
	{
		printf("Texto elemento[%d]: %s <---> ", i, in->elements[i].data);
		printf("Tipo elemento[%d]: %c\n", i, in->elements[i].type);
	}
}
