/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:14:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/24 15:13:50 by pgomez-r         ###   ########.fr       */
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
void	ft_checkprintformat(va_list arg, char *str, size_t *i);
void	ft_putchari(int c, size_t *i);
void	ft_putstri(char *str, size_t *i);
void	ft_putnbri(int n, size_t *i);
void	ft_putunsigi(unsigned int n, size_t *i);
void	ft_puthexalli(unsigned long int n, char *base, size_t *i);

#endif