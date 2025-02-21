
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <sys/stat.h>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <ctime>

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	_rates;
		std::string						_readLine;
		std::string						_key;
		float							_value;
		bool							_firstLine;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void							storeDataBase();
		void							readInput(const std::string &path);

		bool							parseLine();
		bool							checkDate();
		bool							checkDateFormat();
		bool							futureDate(int year_n, int month_n, int day_n);
		bool							checkValue();

		void							calculateValue();
		int								dateDifference(const std::string &date1, const std::string &date2);
};

#endif