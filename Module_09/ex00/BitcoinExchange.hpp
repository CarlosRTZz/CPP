#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	private :
		map<std::string, double> _dataMap;
	public :
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & copy);
		~BitconExhange(void);
		BitcoinExchange &operator=(const BitcoinExchange & rhs);

		bool checkDate(std::string date);

};

#endif