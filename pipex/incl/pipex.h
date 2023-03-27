/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/27 22:53:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libft.h*/
# include "./libft42/libft.h"

/*structs*/
typedef struct s_struct
{
	char	**paths;
	char	*match_path;
	char	*cmd;
}	t_struct;

/*main.c*/
void		get_paths(t_struct *tools, char **env);
int			is_path(char *str);
void		find_path(t_struct *st);

#endif
