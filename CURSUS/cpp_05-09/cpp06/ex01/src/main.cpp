/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:18:03 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/05 17:18:23 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data test;
	test.n = 42;
	test.f = 42.42f;
	test.str = "42 Málaga\n";

	std::cout << "[0]Original variable address: " << &test << std::endl;

	uintptr_t	serialized = Serializer::serialize(&test);
	std::cout << "[1]Serialized variable uintptr_t: " << serialized << std::endl;
	std::cout << "[1]Original variable address: " << &test << std::endl;

	Data*	deserialized = Serializer::deserialize(serialized);
	std::cout << "[2]Deserialized variable addres: " << deserialized << std::endl;
	std::cout << "[2]Deserialized variable->int: " << deserialized->n << std::endl;
	std::cout << "[2]Deserialized variable->float: " << deserialized->f << std::endl;
	std::cout << "[2]Deserialized variable->str: " << deserialized->str << std::endl;
	std::cout << "[2]Original variable address: " << &test << std::endl;

	return (0);
}
