/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:21:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/05 16:16:42 by pgomez-r         ###   ########.fr       */
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
/*ps_utils.c*/
size_t		ft_strdlen(char **str);
size_t		ft_arrlen(int *array);
void		ft_totalfree(char **numbers);
int			*ft_getarray(char **numbers);
/*split_atoi.c*/
int			ft_count_word(char const *s, char c);
char		*ft_savewords(const char *s, unsigned int n);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
/*arg_check.c*/
char		**ft_argtochar(int ac, char **av);
int			ft_chkdup(char **str);
int			ft_chkdigit(char **str);
int			ft_chksort(int *array, size_t array_len);
int			ft_chklimit(char **str);
/*main.c*/
void		ft_leaks(void);

#endif
