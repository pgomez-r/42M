/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:16:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/10 14:43:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

class	notFound : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Element not found in the container");
		}
};

template <typename T>
void	easyFind(T &cont, int n)
{
	typename T::iterator	i = std::find(cont.begin(), cont.end(), n);
	if (std::find(cont.begin(), cont.end(), n) != cont.end())
	{
		int	pos = std::distance(cont.begin(), i);
		std::cout << n << " value found in the container at index " << pos << std::endl;
	}
	else
		throw (notFound());
}


#endif
