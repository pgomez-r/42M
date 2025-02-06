/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:53 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/06 15:26:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Class 'Base' destructor called" << std::endl;
}

Base *generate(void)
{
	srand(time(0));
	int n = rand() % 3;

	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	else
		return (new C());
}

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
	catch(...){
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Object of type B" << std::endl;
		return ;
	}
	catch(...){
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Object of type C" << std::endl;
		return ;
	}
	catch(...){
		std::cout << "Exception caught: dynamic_cast failed or not valid reference: " << std::endl;
	}
}
