/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:13:20 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/05 20:17:59 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

/**
 * TODO: review and understand this "trick" well enough before eval
 */

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
