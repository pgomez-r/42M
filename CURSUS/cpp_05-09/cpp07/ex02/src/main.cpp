/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:18:08 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/06 17:12:36 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>

int main(void)
{
	try
	{
		// Test default constructor
		Array<int>	def_array;
		std::cout << "Array fron {default constructor} size = " << def_array.size() << std::endl;
		// Test parameterized constructor
		Array<int>	param_array(5);
		std::cout << "Array from {parameterized constructor} size = " << param_array.size() << std::endl;

		// Test element access and assignment
		for (unsigned int i = 0; i < param_array.size(); ++i)
			param_array[i] = i * 10;
		std::cout << "Array from {parameterized constructor} elements:" << std::endl;
		for (unsigned int i = 0; i < param_array.size(); ++i)
			std::cout << "- param_array[" << i << "] = " << param_array[i] << std::endl;

		// Test copy constructor
		Array<int> copy_array(param_array);
		std::cout << "Array from {copy constructor} size = " << copy_array.size() << std::endl;
		std::cout << "Array from {copy constructor} elements:" << std::endl;
		for (unsigned int i = 0; i < copy_array.size(); ++i)
			std::cout << "- copy_array[" << i << "] = " << copy_array[i] << std::endl;

		// Test assignment operator and const opertaror[]
		const Array<int> assig_array = param_array;
		std::cout << "Array from {assignment operator} size = " << assig_array.size() << std::endl;
		std::cout << "Array from {assignment operator} elements:" << std::endl;
		for (unsigned int i = 0; i < assig_array.size(); ++i)
			std::cout << "- assig_array[" << i << "] = " << assig_array[i] << std::endl;

		// Test out of bounds exception
		try{
			std::cout << "Trying to acces [10] position in param_array with size '5'..." << std::endl;
			std::cout << param_array[10] << std::endl;
		}
		catch (const std::out_of_range &e){
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		
		// Test parameterized constructor with std::string
        Array<std::string> string_array(3);
        std::cout << "Array from {parameterized constructor} with std::string size = " << string_array.size() << std::endl;
        string_array[0] = "Hola";
        string_array[1] = "Mundo";
        string_array[2] = "42";
        std::cout << "Array from {parameterized constructor} with std::string elements:" << std::endl;
        for (unsigned int i = 0; i < string_array.size(); ++i)
            std::cout << "- string_array[" << i << "] = " << string_array[i] << std::endl;

	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
