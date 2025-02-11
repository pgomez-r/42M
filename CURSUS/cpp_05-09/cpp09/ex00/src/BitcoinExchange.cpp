
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &fileName) : _file(file)
{
	this._rateValues = NULL;
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
		this->_file = src._file;
		this->_rateValues = src._rateValues;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void    BitcoinExchange::validateFile()
{
	std::ifstream   file(this->_file);
	if (!file.is_open())
		//throw exception file not found or not open
	std::string line;
	//check first line - does it have to be exactly "Date | Value"?
	while (std::getline(file, line))
	{
		if (line.find(" | ") == std::string::npos)
			//throw exception invalid file format
	}
	file.close();
}
