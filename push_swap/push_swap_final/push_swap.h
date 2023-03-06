/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:21:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/05 09:04:57 by pgomez-r         ###   ########.fr       */
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

/*structs*/
typedef struct s_index
{
	int		*array_a;
	int		*array_b;
	int		*array_tmp;
	int		*lis;
	int		coords[2];
	size_t	arrlen;
	size_t	size_a;
	size_t	size_b;
	size_t	size_lis;
}			t_index;

typedef struct s_lis_utils
{
	int		*array_len;
	int		*array_index;
	int		*lis;
	size_t	lis_len;
}			t_lis_utils;

/*main.c*/
void		complex_free(t_index *index, char **numbers);
void		easy_free(t_index *index, char **numbers);
/*libft_utils.c*/
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
int			ft_isdigit(int c);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
/*ps_utils.c*/
size_t		ft_strdlen(char **str);
void		ft_totalfree(char **numbers);
int			ft_getarrays(char **numbers, t_index *index);
int			*ft_simpler(t_index *index);
int			*ft_duparray(int *array, size_t arrlen);
/*ps_utils_b.c*/
void		muted_rotate_a(t_index *index);
void		muted_revrot_a(t_index *index);
int			ft_isinarray(int num, int *array, size_t size);
int			ft_max_in_array(int *array, size_t size);
size_t		ft_maxvalue_pos(int *array, size_t len);
/*split_atoi.c*/
int			ft_count_word(char const *s, char c);
char		*ft_savewords(const char *s, unsigned int n);
char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);
/*arg_check.c*/
char		**ft_argtochar(int ac, char **av);
int			ft_chkdup(t_index *index);
int			ft_chkdigit(char **str);
int			ft_chksort(t_index *index);
int			ft_chklimit(char **str);
/*operations_ps.c*/
void		swap_a(t_index *index);
void		swap_b(t_index *index);
void		push_a(t_index *index);
void		push_b(t_index *index);
/*operations_rot.c*/
void		rotate_a(t_index *index);
void		rotate_b(t_index *index);
void		revrot_a(t_index *index);
void		revrot_b(t_index *index);
/*operations_db.c*/
void		swap_ab(t_index *index);
void		rotate_ab(t_index *index);
void		revrot_ab(t_index *index);
/*lis_utils.c*/
void		lis_len_index(int *array, t_lis_utils *utils, size_t size);
int			*generate_lis(int *array, t_lis_utils *utils, size_t size);
int			*ft_lis(int *array, size_t size, size_t *size_lis);
/*sort_easy.c*/
void		sort_three(t_index *index);
size_t		ft_minvalue_pos(int *array, size_t len);
void		sort_easy(t_index *index);
/*sort_complex.c*/
void		sort_complex(t_index *index);
void		ft_lis_stack(t_index *index);
void		lis_comparepush(t_index *index);
void		best_pos_pusha(t_index *index);
int			calc_moves_in_a(t_index *index, int n);
/*operations_maker.c*/
void		operation_maker(t_index *index);
void		best_rotate_bot(t_index *index, int x, int y);
void		best_rotate_top(t_index *index, int x, int y);
int			ft_abs_sum(int x, int y);

#endif
