/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/21 20:36:22 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libft.h*/
# include "./libft42/libft.h"

/*structs*/
typedef struct s_struct
{
	int		cmd_n;
	int		fd_in;
	int		fd_out;
}	t_struct;

typedef struct s_command
{
	char	**paths;
	char	*path_cmd;
	char	**cmd;
}	t_command;

/*main.c*/
void		ft_pipex(char *cmd, char **env, int fd);
void		ft_exegguttor(char *cmd, char **env);

/*parser.c*/
int			is_path(char *str);
void		get_paths(t_command *st, char **env);
int			find_path_index(t_command *st, char *cmd);
void		split_cmd(t_command *st, char *cmdstr);

/*utils.c*/
void		ft_openfiles(t_struct *d, char **av, int i);
void		free_cache(t_command *st, int error);

#endif
