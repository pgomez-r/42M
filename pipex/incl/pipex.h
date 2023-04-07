/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/07 21:09:37 by pgomez-r         ###   ########.fr       */
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
	char	**path_cmd;
	char	*cmd;
	char	**cmd_opt;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		*pids;
	pid_t	pid;
}	t_struct;

/*main.c*/
void		get_paths(t_struct *st);
int			ft_pipex(t_struct *st);

/*init_data.c*/
t_struct	init_struct(int ac, char **av, char **env);
t_struct	set_st_empty(void);

/*parser.c*/
int			is_path(char *str);
void		get_paths(t_struct *st);
int			find_path_index(t_struct *st);
void		get_iofiles(t_struct *st);

/*utils.c*/
void		ft_print_dstr(char **dstr);
void		ft_leaks(void);
void		exit_pipex(t_struct *st);
void		close_pipe(t_struct *st);
void		close_fds(t_struct *st);

#endif
