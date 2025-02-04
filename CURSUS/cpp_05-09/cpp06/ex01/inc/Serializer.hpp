/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:55:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/01/31 14:56:21 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

/**
 * TODO: check if struct definition is allowed in the Class.hpp file by the norm
 */

struct Data
{
	int			n;
	float		f;
	std::string	str;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &src);
		~Serializer(void);
		Serializer &operator=(const Serializer &src);
	public:
		static uintptr_t	serialize(Data	*ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
