/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 01:18:02 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 4)
		return (printf("Few arguments\n"), 1);
	char	*options[3];

	options[0] = "ls";
	options[1] = "-la";
	options[2] = NULL;
	(void)ac;
	(void)av;
	execve("/usr/bin/ls", options, env);	
	return (0);
}
