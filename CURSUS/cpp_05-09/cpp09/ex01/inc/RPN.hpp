/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:01:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/14 23:59:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class	RPN
{
	private:
		std::string			_input;
		std::stack<int>		_stack;
		int					_result;
		RPN();
	
	public:
		RPN(std::string input);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void	calculate();
		bool	isOp(const std::string &token);
		bool	doOp(const std::string &token);
		bool	updateStack(const std::string &token);
};

#endif