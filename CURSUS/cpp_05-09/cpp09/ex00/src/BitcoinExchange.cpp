/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:10:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/21 16:52:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_readLine.clear();
	this->_rates.clear();
	this->_key.clear();
	this->_value = 0;
	this->_firstLine = true;
	try
	{
		this->storeDataBase();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		throw ;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_readLine = src._readLine;
		this->_rates = src._rates;
		this->_key = src._key;
		this->_value = src._value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::storeDataBase()
{
	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw (std::runtime_error("Could not open file: data.csv"));
	
	std::string		line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t delim = line.find(',');
		if (delim == std::string::npos)
			throw (std::runtime_error("Invalid line format: " + line));

		std::string date = line.substr(0, delim);
		std::string value = line.substr(delim + 1);

		date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
		date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
 		value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
		value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
		
		this->_rates[date] = atof(value.c_str());
	}
	file.close();
}

void	BitcoinExchange::readInput(const std::string &path)
{
	struct stat	buffer;
	if (stat(path.c_str(), &buffer) != 0)
		throw std::runtime_error("File not found: " + path);

	std::ifstream  	file(path.c_str());
	if (!file.is_open())
		throw (std::runtime_error("Could not find or open file: " + path));
	while (std::getline(file, this->_readLine))
	{	
		if (this->parseLine())
			this->calculateValue();
		this->_readLine.clear();
		this->_firstLine = false;
	}
	file.close();
}

bool	BitcoinExchange::parseLine()
{
	size_t delim = this->_readLine.find('|');
	if (delim == std::string::npos)
	{
		if (this->_readLine.empty())
			std::cout << "Error: invalid line format (missing '|' separator): <EMPTY_LINE>" << std::endl;
		else
			std::cout << "Error: invalid line format (missing '|' separator): " << this->_readLine << std::endl;
		return (false);
	}
	this->_key = this->_readLine.substr(0, delim);
	std::string value_str = this->_readLine.substr(delim + 1);
	this->_key.erase(0, this->_key.find_first_not_of(" \t\n\r\f\v"));
	this->_key.erase(this->_key.find_last_not_of(" \t\n\r\f\v") + 1);
	value_str.erase(0, value_str.find_first_not_of(" \t\n\r\f\v"));
	value_str.erase(value_str.find_last_not_of(" \t\n\r\f\v") + 1);
	if (!this->checkDate())
		return (false);
	char *ptr;
	this->_value = strtof(value_str.c_str(), &ptr);
	if (*ptr != '\0')
	{
		std::cout << "Error: invalid value format: " << value_str << std::endl;
		return (false);
	}
	if (!this->checkValue())
		return (false);
	return (true);
}

bool	BitcoinExchange::checkDate()
{
	if (!checkDateFormat())
		return (false);

	std::string	year = this->_key.substr(0, 4);
	std::string	month = this->_key.substr(5, 2);
	std::string	day = this->_key.substr(8, 2);
	int			year_n = atoi(year.c_str());
	int			month_n = atoi(month.c_str());
	int			day_n = atoi(day.c_str());
	int 		calendar[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (year_n < 0)
	{
		std::cout << "Error: invalid year in date: " << this->_key << std::endl;
		return (false);
	}
	if (month_n < 1 || month_n > 12)
	{
		std::cout << "Error: invalid month in date: " << this->_key << std::endl;
		return (false);
	}
	if ((year_n % 4 == 0 && year_n % 100 != 0) || (year_n % 400 == 0))
		calendar[1] = 29;
	if (day_n < 1 || day_n > calendar[month_n - 1])
	{
		std::cout << "Error: invalid day in date: " << this->_key << std::endl;
		return (false);
	}
	return (this->futureDate(year_n, month_n, day_n));
}

bool	BitcoinExchange::checkDateFormat()
{
	if (this->_key.size() != 10)
	{
		if (!this->_firstLine)
			std::cout << "Error: invalid date format: " << this->_key << std::endl;
		return (false);
	}
	for (size_t i = 0; i < this->_key.size(); ++i)
	{
		if ((i == 4 || i == 7) && this->_key[i] != '-')
		{
			if (!this->_firstLine)
				std::cout << "Error: invalid date format: " << this->_key << std::endl;
			return (false);
		}
		else if (i != 4 && i != 7 && !isdigit(this->_key[i]))
		{
			if (!this->_firstLine)
				std::cout << "Error: invalid date format: " << this->_key << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::futureDate(int year_n, int month_n, int day_n)
{
	time_t		t = time(0);
	struct tm	*now = localtime(&t);
	int			current_year = now->tm_year + 1900;
	int			current_month = now->tm_mon + 1;
	int			current_day = now->tm_mday;

	if (year_n > current_year || 
		(year_n == current_year && month_n > current_month) || 
		(year_n == current_year && month_n == current_month && day_n > current_day))
	{
		std::cout << "Error: date is ahead of the current date: " << this->_key << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkValue()
{
	if (this->_value < 0)
	{
		std::cout << "Error: not a positive number: " << std::fixed << std::setprecision(2) << this->_value << std::endl;
		return (false);
	}
	if (this->_value > 1000)
	{
		std::cout << "Error: too large a number: " << std::fixed << std::setprecision(2) << this->_value << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::calculateValue()
{
	std::map<std::string, float>::iterator	closest = _rates.end();
	int 									minDiff = INT_MAX;
	float									exchage_value;

	for (std::map<std::string, float>::iterator i = _rates.begin(); i != _rates.end(); ++i)
	{
		int diff = dateDifference(i->first, this->_key);
		if (diff <= 0 && abs(diff) < minDiff)
		{
			minDiff = abs(diff);
			closest = i;
		}
	}
	if (closest == _rates.end())
	{
		minDiff = INT_MAX;
		for (std::map<std::string, float>::iterator i = _rates.begin(); i != _rates.end(); ++i)
		{
			int diff = dateDifference(i->first, this->_key);
			if (diff > 0 && diff < minDiff)
			{
				minDiff = diff;
				closest = i;
			}
		}
	}
	exchage_value = closest->second * this->_value;
	std::cout << this->_key << " => " << closest->first << " | " << this->_value << " * "; 
	std::cout << closest->second << " = " << exchage_value << std::endl;
}

int	BitcoinExchange::dateDifference(const std::string &date1, const std::string &date2)
{
	int year1 = atoi(date1.substr(0, 4).c_str());
	int month1 = atoi(date1.substr(5, 2).c_str());
	int day1 = atoi(date1.substr(8, 2).c_str());

	int year2 = atoi(date2.substr(0, 4).c_str());
	int month2 = atoi(date2.substr(5, 2).c_str());
	int day2 = atoi(date2.substr(8, 2).c_str());

	return ((year1 - year2) * 365 + (month1 - month2) * 30 + (day1 - day2));
}
