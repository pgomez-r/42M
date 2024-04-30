/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:46:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/30 17:11:13 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class	Contact
{
	private:
		std::string	name;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		int			index;
		std::string	ft_formatStr(std::string str);
	public:
		Contact();
		~Contact();
		int		fill_info(int i);
		void	preview(void);
		int		display_all(void);
};

int	ft_readInput(std::string *input, int mode);

#endif