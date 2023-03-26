/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/26 21:01:18 by pgomez-r         ###   ########.fr       */
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
}	t_struct;

/*main.c*/
void		ft_paths(t_struct *tools, char **env);
int			is_path(char *str);

#endif
