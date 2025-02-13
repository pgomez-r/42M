
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_readLine.clear();
	this->_rates.clear();
	this->_key.clear();
	this->_value = 0;
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

// BitcoinExchange::BitcoinExchange(const std::string &path) : _inputPath(path)
// {
// }

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
 
		std::stringstream	aux(value);
		float				rate;
		aux >> rate;
		if (aux.fail())
			throw (std::runtime_error("Invalid value format: " + value));
		this->_rates[date] = rate;
	}
	file.close();
}

void	BitcoinExchange::readFile(const std::string &path)
{
	struct stat	buffer;
	if (stat(path.c_str(), &buffer) != 0)
		throw std::runtime_error("File not found: " + path);

	std::ifstream  	file(path);
	if (!file.is_open())
		throw (std::runtime_error("Could not find or open file: " + path));

	while (std::getline(file, this->_readLine))
	{	
		this->readLine();
		this->_readLine.clear();
	}
	file.close();
}

void	BitcoinExchange::readLine()
{
	if (this->isLineValid())
		this->calculateValue();
}

bool	BitcoinExchange::isLineValid()
{
	return (true);
}

void	BitcoinExchange::calculateValue()
{

}
