/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:53 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/01/31 15:04:04 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**
 * TODO: Check if function implementation is allowd in this file
 */

Base::~Base()
{
	std::cout << "Class 'Base' destructor called" << std::endl;
}

Base *generate(void)
{
	int n = rand() % 3;

	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	else
		return (new C());
}

/**
 * TODO: Check why there is no need to try/catch in this function
 */
void identify(Base *p)
{
	if (!p)
	{
		std::cout << "NULL pointer" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "Object of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Object of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Object of type C" << std::endl;
	else
		std::cout << "Not valid pointer" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Object of type A" << std::endl;
		return ;
	}
	catch(std::bad_cast &e){
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Object of type A B" << std::endl;
		return ;
	}
	catch(std::bad_cast &e){
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Object of type A C" << std::endl;
		return ;
	}
	catch(std::bad_cast &e){
		std::cout << "Not valid reference: " << e.what() << std::endl;
	}
}
