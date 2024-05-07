/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:36:54 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 19:21:40 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <iostream>
#include <fstream>

class   FileReplace
{
    private:
        std::string inFile;
        std::string outFile;
    public:
        FileReplace(std::string filePath);
        ~FileReplace();
        void    ftReplace(std::string target, std::string swap);
};

#endif