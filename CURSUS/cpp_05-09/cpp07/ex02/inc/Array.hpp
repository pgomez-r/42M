/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:18:58 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/06 17:10:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		Array &operator=(const Array &src);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;

	private:
		T* 				_data;
		unsigned int 	_size;
};

#include "../src/Array.tpp"

#endif
