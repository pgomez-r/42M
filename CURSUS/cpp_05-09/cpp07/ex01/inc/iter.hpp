/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:13:20 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/06 15:24:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, int length, F function)
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void iter(T *array, int length, void (*function)(const T &))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

#endif
