/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:37 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/25 21:37:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif

/*libs_estandar*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>

/*ESTRUCURAS*/
/*listas libft*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/*index_push*/
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
/*estructura para LIS*/
typedef struct s_lis_utils
{
	int		*array_len;
	int		*array_index;
	int		*lis;
	size_t	lis_len;
}			t_lis_utils;

/*FUNCIONES ft_utils*/
void		ft_leaks(void);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
size_t		ft_strdlen(char **str);
void		ft_totalfree(char **numbers);
int			ft_getarrays(char **numbers, t_index *index);
int			*ft_simpler(t_index *index);
int			*ft_duparray(int *array, size_t arrlen);
int			ft_isinarray(int num, int *array, size_t size);
int			ft_max_in_array(int *array, size_t size);
size_t		ft_maxvalue_pos(int *array, size_t len);
long int	ft_latoi(const char *str);
char		**ft_argtochar(int ac, char **av);
int			ft_chkdup(t_index *index);
int			ft_chkdigit(char **str);
int			ft_chksort(t_index *index);
int			ft_chklimit(char **str);
size_t		ft_minvalue_pos(int *array, size_t len);
int			ft_abs_sum(int x, int y);
void		ft_print_dstr(char **dstr);

/*FUNCIONES DE LIBFT*/
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t count);
void		*ft_memset(void *str, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char const *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *hs, const char *nd, size_t n);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_lstadd_back(t_list **lst, t_list *newl);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

/*FUNCIONES DE PRINTF*/
int			ft_printf(char const *str, ...);
void		ft_checkprintformat(va_list arg, char *str, size_t *i);
void		ft_putchari(int c, size_t *i);
void		ft_putstri(char *str, size_t *i);
void		ft_putnbri(int n, size_t *i);
void		ft_putunsigi(unsigned int n, size_t *i);
void		ft_puthexalli(unsigned long int n, char *base, size_t *i);

/*ft_printf_error -> imprimir con ft_print por salida de errores (fd = 2)*/
void		ft_putchari_error(int c, size_t *i);
int			ft_printf_error(char const *str, ...);
void		ft_checkprintformat_error(va_list arg, char *str, size_t *i);
void		ft_putchari_error(int c, size_t *i);
void		ft_putstri_error(char *str, size_t *i);
void		ft_putnbri_error(int n, size_t *i);
void		ft_putunsigi_error(unsigned int n, size_t *i);
void		ft_puthex_error(unsigned long int n, char *base, size_t *i);

/*GNL*/
char		*get_next_line(int fd);
char		*join_and_free(char *stack, char *tmp);
char		*update_stack(char *stack);
char		*create_line(char *stack);

/*PUSH_SWAP*/
void		complex_free(t_index *index, char **numbers);
void		easy_free(t_index *index, char **numbers);
void		muted_rotate_a(t_index *index);
void		muted_revrot_a(t_index *index);
void		swap_a(t_index *index);
void		swap_b(t_index *index);
void		push_a(t_index *index);
void		push_b(t_index *index);
void		rotate_a(t_index *index);
void		rotate_b(t_index *index);
void		revrot_a(t_index *index);
void		revrot_b(t_index *index);
void		swap_ab(t_index *index);
void		rotate_ab(t_index *index);
void		revrot_ab(t_index *index);
void		sort_three(t_index *index);
void		sort_easy(t_index *index);
void		sort_complex(t_index *index);
void		ft_lis_stack(t_index *index);
void		lis_comparepush(t_index *index);
void		best_pos_pusha(t_index *index);
int			calc_moves_in_a(t_index *index, int n);
void		operation_maker(t_index *index);
void		best_rotate_bot(t_index *index, int x, int y);
void		best_rotate_top(t_index *index, int x, int y);

/*ft_LIS*/
void		lis_len_index(int *array, t_lis_utils *utils, size_t size);
int			*generate_lis(int *array, t_lis_utils *utils, size_t size);
int			*ft_lis(int *array, size_t size, size_t *size_lis);

#endif