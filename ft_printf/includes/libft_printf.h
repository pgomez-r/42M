/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:14:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/17 14:20:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		tlen;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
}	t_print;

#endif
