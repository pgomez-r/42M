/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:10 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 08:43:12 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);
	
		Dog	&operator=(const Dog &rhs);
	
		void	makeSound(void) const;
		std::string	getBrain(void) const;
		void	fillBrain(std::string input);
};

#endif