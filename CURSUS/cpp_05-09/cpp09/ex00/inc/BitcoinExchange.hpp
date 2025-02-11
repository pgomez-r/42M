
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class	BitcoinExchange
{
	private:
		const std::string				_file;
		std::map<std::string, float>	_rateValues;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
	public:
		BitcoinExchange(const std::string &fileName);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	validateFile();
};

#endif