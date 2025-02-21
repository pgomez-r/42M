/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:01:47 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/21 18:09:53 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string input)
{
	this->_input = input;
	this->_result = 0;
}

RPN::RPN(const RPN &src)
{
	if (this != &src)
		*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_result = src._result;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::calculate()
{
	std::string			clean_input;
	for (size_t i = 0; i < this->_input.size(); i++)
	{
		char c = this->_input[i];
		if (isOp(std::string(1, c)))
		{
			if (!clean_input.empty() && this->_input[i - 1] != ' ')
				clean_input += ' ';
			clean_input += c;
			if (i < this->_input.size() - 1 && this->_input[i + 1] != ' ')
				clean_input += ' ';
		}
		else
			clean_input += c;
	}

	std::istringstream	iss(clean_input);
	std::string 		token;
	while (std::getline(iss, token, ' '))
	{
		if (isOp(token))
		{
			if (!doOp(token))
				return ;
		}
		else
		{
			if (!updateStack(token))
				return ;
		}
	}

	if (iss.eof())
	{
		this->_result = this->_stack.top();
		std::cout << this->_result << std::endl;
	}
}

bool RPN::isOp(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::doOp(const std::string &token)
{
	if (this->_stack.size() < 2)
	{
		std::cerr << "Error: not enough operands" << std::endl;
		return (false);
	}

	int	a = this->_stack.top();
	this->_stack.pop();
	int	b = this->_stack.top();
	this->_stack.pop();

	if (token == "+")
		this->_stack.push(b + a);
	else if (token == "-")
		this->_stack.push(b - a);
	else if (token == "*")
		this->_stack.push(b * a);
	else if (token == "/")
	{
		if (a == 0)
		{
			std::cerr << "Error: division by zero" << std::endl;
			return (false);
		}
		this->_stack.push(b / a);
	}

	return (true);
}

bool RPN::updateStack(const std::string &token)
{
	try
	{
		float value;
		std::stringstream ss(token);
		ss >> value;
		if (ss.fail() || !ss.eof())
			throw std::invalid_argument("Invalid token");
		this->_stack.push(value);
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: invalid token" << std::endl;
		return (false);
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Error: token out of range '" << token << "'" << std::endl;
		return (false);
	}

	return (true);
}
