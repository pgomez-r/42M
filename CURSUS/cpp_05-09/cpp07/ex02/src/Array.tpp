/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:18:54 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/07 12:11:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_data = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_data = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->_data = new T[src._size];
	this->_size = src._size;
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = src._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] (_data);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] (_data);
		_size = src._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = src._data[i];
	}
	return (*this);
}


template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::out_of_range("Index out of bounds"));
	return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (std::out_of_range("Index out of bounds"));
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
