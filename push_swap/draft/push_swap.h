/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:21:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/18 14:30:48 by pgomez-r         ###   ########.fr       */
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

/*struct*/
typedef struct s_index
{
	size_t	arrlen_a;
	size_t	numlen_a;
	size_t	arrlen_a;
	size_t	numlen_a;
}			t_index;

/*main.c*/
void		ft_leaks(void);
/*libft_utils.c*/
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
int			ft_isdigit(int c);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
/*ps_utils.c*/
size_t		ft_strdlen(char **str);
void		ft_totalfree(char **numbers);
int			*ft_getarray(char **numbers, t_index *index);
int			*ft_simpler(int	*array, size_t len);
int			*ft_arraycalloc(size_t arrlen);
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
/*operations_ps.c*/
void		swap_a(int *array_a, size_t arrlen);
void		swap_b(int *array_b, size_t arrlen);
void		swap_ab(int *array_a, int*array_b, size_t arrlen);
void		push_a(int *array_a, int *array_b, size_t arrlen);
void		push_b(int *array_a, int *array_b, size_t arrlen);
/*operations_rot.c*/
void		rotate_a(int *array_a, size_t arrlen);
void		rotate_b(int *array_b, size_t arrlen);
void		revrot_a(int *array_a, size_t arrlen);
void		revrot_b(int *array_b, size_t arrlen);
/*operations_db*/
void		rotate_ab(int *array_a, int *array_b, size_t arrlen);
void		revrot_ab(int *array_a, int *array_b, size_t arrlen);

#endif
