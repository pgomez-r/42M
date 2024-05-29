/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:24:19 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 04:34:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		WrongAnimal &operator=(const WrongAnimal &rhs);
		
		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif
