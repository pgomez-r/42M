/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:31:51 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/13 11:52:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	easyFind(T &cont, int n)
{
	typename T::iterator	i = std::find(cont.begin(), cont.end(), n);
	if (std::find(cont.begin(), cont.end(), n) != cont.end())
	{
		int	pos = std::distance(cont.begin(), i);
		std::cout << "Value \"" << n << "\" found in the container at index " << pos << std::endl;
	}
	else
		throw (std::runtime_error("Element not found in the container"));
}
