/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:30:53 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 12:43:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str;
    std::string *stringPTR;
    std::string &stringREF = str;

    str = "HI THIS IS BRAN";
    stringPTR = &str;
    
    std::cout << "MEM ADDRESS of the string VARIABLE: " << &str << std::endl; 
    std::cout << "MEM ADDRESS of the string POINTER: " << stringPTR << std::endl; 
    std::cout << "MEM ADDRESS of the string REFERENCE: " << &stringREF << std::endl << std::endl; 
    
    std::cout << "VALUE of the string VARIABLE: " << str << std::endl;
    std::cout << "VALUE of the string POINTER: " << *stringPTR << std::endl;
    std::cout << "VALUE of the string REFERENCE: " << stringREF << std::endl;

    return (0);
}
