/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:55:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/05 17:45:02 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

/**
 * TODO: check if struct definition is allowed in the Class.hpp file by the norm/subject
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
