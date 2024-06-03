/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:12:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/30 16:57:53 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class	PhoneBook
{
	private:
		Contact contact[8];
		int		max;
		int		oldest;
	public:	
		PhoneBook();
		~PhoneBook();
		void	prompt(void);
		int		add(void);
		int		search(void);
};

#endif