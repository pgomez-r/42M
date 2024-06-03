/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:17 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 08:47:56 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int	main(void)
{
	std::cout << "[ --- STACK ALLOCATION TEST --- ]" << std::endl;
	std::cout << "--- CAT & DOG DEFAULT & COPY CONSTRUCTION ---" << std::endl;

	Cat		c_def;
	Cat		c_cpy(c_def);
	std::cout << std::endl;

	Dog		d_def;
	Dog		d_cpy(d_def);
	std::cout << std::endl;

	std::cout << "--- TYPES CHECK ---" << std::endl;
	std::cout << c_def.getType() << std::endl;	
	std::cout << c_cpy.getType() << std::endl;	
	std::cout << std::endl;
	std::cout << d_def.getType() << std::endl;	
	std::cout << d_cpy.getType() << std::endl;	
	std::cout << std::endl;

	std::cout << "--- SOUNDS CHECK ---" << std::endl;
	c_def.makeSound();
	c_cpy.makeSound();
	std::cout << std::endl;
	d_def.makeSound();
	d_cpy.makeSound();
	std::cout << std::endl;

	std::cout << "[ --- HEAP ALLOCATION ARRAY TEST --- ]" << std::endl;
	std::cout << "--- CAT & DOG CONSTRUCTION AND CHECKING ---" << std::endl;
	
	Animal	*animals_array[6];
	int		i;

	for (i = 0; i < 6; i++)
	{
		std::cout << "-- Creating ANIMAL NUMBER [" << (i + 1) << "] --" << std::endl;
		if (i % 2 == 0)
			animals_array[i] = new Cat();
		else
			animals_array[i] = new Dog();
		std::cout << "Animal number " << (i + 1) << ": " <<animals_array[i]->getType() << std::endl;
		std::cout << "Animal number " << (i + 1) << " says: ";
		animals_array[i]->makeSound();
	}
	std::cout << std::endl;
	
	std::cout << "--- HEAP DELETION ---" << std::endl;
	while (--i >= 0)
	{
		std::cout << "-- Deleting ANIMAL NUMBER [" << (i + 1) << "] --" << std::endl;
		delete (animals_array[i]);
	}
	std::cout << std::endl;

	std::cout << "[ --- CONCRETE BRAIN TEST --- ]" << std::endl;
	Dog	basic;
	basic.fillBrain("You know nothing Jon Snow");
	{
		Dog	temp = basic;
		std::cout << "Basic brain: " << basic.getBrain() << std::endl;
		std::cout << "Temp brain: " << temp.getBrain() << std::endl;
		std::cout << "Changing brain ideas for temp dog..." << std::endl;
		temp.fillBrain("Winter is coming (after summer and fall...)");
		std::cout << "Basic brain: " << basic.getBrain() << std::endl;
		std::cout << "Temp brain: " << temp.getBrain() << std::endl;
		std::cout << "Exiting 'Dog temp' scope..." << std::endl;
	}
	std::cout << "Basic brain again: " << basic.getBrain() << std::endl;
	std::cout << std::endl;

	std::cout << "--- STACK DELETION ---" << std::endl;
	return (0);	
}
