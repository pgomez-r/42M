/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:17 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 00:05:26 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - DELETION in a function?

#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << "[ --- STACK ALLOCATION TEST MODE --- ]" << std::endl;
		std::cout << "--- ANIMAL, CAT & DOG CONSTRUCTION ---" << std::endl;
		Animal	a_def;
		Animal	a_typ("Random");
		Animal	a_cpy(a_typ);
		std::cout << std::endl;

		Cat		c_def;
		Cat		c_cpy(c_def);
		std::cout << std::endl;

		Dog		d_def;
		Dog		d_cpy(d_def);
		std::cout << std::endl;

		std::cout << "--- TYPES CHECK ---" << std::endl;
		std::cout << a_def.getType() << std::endl;	
		std::cout << a_typ.getType() << std::endl;	
		std::cout << a_cpy.getType() << std::endl;	
		std::cout << std::endl;
		std::cout << c_def.getType() << std::endl;	
		std::cout << c_cpy.getType() << std::endl;	
		std::cout << std::endl;
		std::cout << d_def.getType() << std::endl;	
		std::cout << d_cpy.getType() << std::endl;	
		std::cout << std::endl;

		std::cout << "--- SOUNDS CHECK ---" << std::endl;
		a_def.makeSound();
		a_cpy.makeSound();
		std::cout << std::endl;
		c_def.makeSound();
		c_cpy.makeSound();
		std::cout << std::endl;
		d_def.makeSound();
		d_cpy.makeSound();
		std::cout << std::endl;

		std::cout << "--- WRONG ANIMALS CONSTRUCTION ---" << std::endl;
		WrongAnimal	wa_def;
		WrongAnimal	wa_cpy(wa_def);
		std::cout << std::endl;

		WrongCat	wc_def;
		WrongCat	wc_cpy(wc_def);
		std::cout << std::endl;

		std::cout << "--- TYPES CHECK ---" << std::endl;
		std::cout << wa_def.getType() << std::endl;	
		std::cout << wa_cpy.getType() << std::endl;	
		std::cout << std::endl;
		std::cout << wc_def.getType() << std::endl;	
		std::cout << wc_cpy.getType() << std::endl;	
		std::cout << std::endl;

		std::cout << "--- SOUNDS CHECK ---" << std::endl;
		wa_def.makeSound();
		wa_cpy.makeSound();
		std::cout << std::endl;
		wc_def.makeSound();
		wc_cpy.makeSound();
		std::cout << std::endl;
	}
	else
	{
		std::cout << "[ --- HEAP ALLOCATION TEST MODE --- ]" << std::endl;
		std::cout << "--- ANIMAL, CAT & DOG CONSTRUCTION ---" << std::endl;
		Animal	*a_def = new Animal();
		Animal	*a_typ = new Animal("Random");
		Animal	*a_cpy = new Animal(*a_typ);
		std::cout << std::endl;

		Animal		*c_def = new Cat();
		Cat			*c_cpy = new Cat(*dynamic_cast<Cat*>(c_def));
		std::cout << std::endl;

		Animal		*d_def = new Dog();
		Dog			*d_cpy = new Dog(*dynamic_cast<Dog*>(d_def));
		std::cout << std::endl;

		std::cout << "--- TYPES CHECK ---" << std::endl;
		std::cout << a_def->getType() << std::endl;	
		std::cout << a_typ->getType() << std::endl;	
		std::cout << a_cpy->getType() << std::endl;	
		std::cout << std::endl;
		std::cout << c_def->getType() << std::endl;	
		std::cout << c_cpy->getType() << std::endl;	
		std::cout << std::endl;
		std::cout << d_def->getType() << std::endl;	
		std::cout << d_cpy->getType() << std::endl;	
		std::cout << std::endl;

		std::cout << "--- SOUNDS CHECK ---" << std::endl;
		a_def->makeSound();
		a_cpy->makeSound();
		std::cout << std::endl;
		c_def->makeSound();
		c_cpy->makeSound();
		std::cout << std::endl;
		d_def->makeSound();
		d_cpy->makeSound();
		std::cout << std::endl;

		std::cout << "--- DELETION ---" << std::endl;
		delete	a_def;
		delete	a_typ;
		delete	a_cpy;
		delete	c_def;
		delete	c_cpy;
		delete	d_def;
		delete	d_cpy;
		std::cout << std::endl;

		std::cout << "--- WRONG ANIMALS CONSTRUCTION ---" << std::endl;
		WrongAnimal	*wa_def = new WrongAnimal();
		WrongAnimal	*wa_cpy = new WrongAnimal(*wa_def);
		std::cout << std::endl;

		WrongAnimal	*wc_def = new WrongCat();
		WrongCat	*wc_cpy = new WrongCat(*dynamic_cast<WrongCat*>(wc_def));
		std::cout << std::endl;
		
		std::cout << "--- TYPES CHECK ---" << std::endl;
		std::cout << wa_def->getType() << std::endl;	
		std::cout << wa_cpy->getType() << std::endl;	
		std::cout << std::endl;
		std::cout << wc_def->getType() << std::endl;	
		std::cout << wc_cpy->getType() << std::endl;	
		std::cout << std::endl;

		std::cout << "--- SOUNDS CHECK ---" << std::endl;
		wa_def->makeSound();
		wa_cpy->makeSound();
		std::cout << std::endl;
		wc_def->makeSound();
		wc_cpy->makeSound();
		std::cout << std::endl;
		
		std::cout << "--- DELETION ---" << std::endl;
		delete	wa_def;
		delete	wa_cpy;
		delete	wc_def;
		delete	wc_cpy;
		std::cout << std::endl;
	}
	return (0);	
}
