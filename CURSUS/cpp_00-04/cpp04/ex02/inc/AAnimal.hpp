/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:06 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 00:09:23 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal(void);

		AAnimal &operator=(const AAnimal &rhs);
		
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif