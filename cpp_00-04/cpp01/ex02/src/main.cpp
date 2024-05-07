/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:30:53 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 04:09:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: pointer vs reference? RESEARCH!

#include <iostream>

int main(void)
{
    std::string str;
    std::string *ptr;
    std::string &ref = str;

    str = "HI THIS IS BRAN";
    ptr = &str;
    
    std::cout << "MEM ADDRESS of the string VARIABLE: " << &str << std::endl; 
    std::cout << "MEM ADDRESS of the string POINTER: " << ptr << std::endl; 
    std::cout << "MEM ADDRESS of the string REFERENCE: " << &ref << std::endl << std::endl; 
    
    std::cout << "VALUE of the string VARIABLE: " << str << std::endl;
    std::cout << "VALUE of the string POINTER: " << *ptr << std::endl;
    std::cout << "VALUE of the string REFERENCE: " << ref << std::endl;

    return (0);
}
