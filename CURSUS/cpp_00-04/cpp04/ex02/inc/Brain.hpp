/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:17:11 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/30 08:39:54 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>

class	Brain{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);
	
		Brain	&operator=(const Brain &rhs);
		std::string	getIdeas(void);
		void		setIdeas(std::string input);
};

#endif
