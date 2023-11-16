/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/24 21:10:56 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libft.h*/
# include "./libft42/libft.h"

/*structs*/
typedef struct s_struct
{
	int		ac;
	char	**av;
	char	**env;
	char	**paths;
	char	*path_cmd;
	char	**cmd1;
	char	**cmd2;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	pid_t	pid_child;
	int		error_flag;
}	t_struct;

/*main.c*/
void		ft_pipex(t_struct *st);
void		parent_proc(t_struct *st);
void		child_proc(t_struct	*st);

/*init.c*/
t_struct	init_struct(int ac, char **av, char **env);
t_struct	set_st_empty(void);
void		pipe_gen(t_struct *st);

/*parser.c*/
int			is_path(char *str);
void		get_paths(t_struct *st);
int			find_path_index(t_struct *st, char *cmd);
void		commands_parser(t_struct *st);

/*utils.c*/
void		exit_pipex(t_struct *st, int error);
void		close_pipe(t_struct *st);
void		close_fds(t_struct *st);

#endif
