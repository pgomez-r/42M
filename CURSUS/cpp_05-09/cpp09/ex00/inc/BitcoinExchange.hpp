
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <sys/stat.h>
#include <stdexcept>
#include <string>

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	_rates;
		std::string						_readLine;
		std::string						_key;
		float							_value;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		//BitcoinExchange(const std::string &fileName);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	storeDataBase();
		void	readFile(const std::string &path);
		void    readLine();
		bool	isLineValid();
		void	calculateValue();
};

#endif