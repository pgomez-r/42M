/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:21:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/24 03:12:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000

# endif

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
	int		flag;
}			t_index;

/*main.c*/
void		easy_free(t_index *index, char **numbers);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			chose_op(t_index *index, char *ops);
int			checker(t_index	*index);
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
/*get_next_line.c*/
char		*create_line(char *stack);
char		*update_stack(char *stack);
char		*join_and_free(char *stack, char *tmp);
char		*get_next_line(int fd);
/*get_next_line_utils.c*/
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);

#endif
