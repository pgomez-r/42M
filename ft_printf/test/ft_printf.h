/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:14:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/22 08:17:53 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
void	ft_checkformat(va_list arg, char *str, size_t *i);
void	ft_putchar(int c, size_t *i);
void	ft_putstr(char *str, size_t *i);
void	ft_putnbr(int n, size_t *i);
void	ft_putunsig(unsigned int n, size_t *i);
void	ft_puthexall(unsigned long int n, char *base, size_t *i);

#endif