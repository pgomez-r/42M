/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:21:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/30 13:05:48 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

/*libft_utils.c*/
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
int			ft_isdigit(int c);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
/*split_atoi.c*/
int			ft_count_word(char const *s, char c);
char		*ft_savewords(const char *s, unsigned int n);
char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);
/*arg_check.c*/
int			ft_checkduplicates(char **str);
int			ft_checkargs(char **numbers);
size_t		ft_strdlen(char **str);
int			ft_checksorted(int *array, size_t array_len);
/*main.c*/
void		ft_totalfree(char **numbers);

#endif
