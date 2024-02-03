#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange {
	private :
		std::map<std::string, double> _dataMap;
		void trimLeft(std::string& toTrim);
		void trimRight(std::string& toTrim);
		bool onlyDigit(std::string value);
		bool isValidDateRange(int year, int month, int day);
		bool validDate(std::string date);
		bool validValue(std::string value);
		bool validValueInput(std::string value);
		bool checkValue(std::string valueStr, double& value);
		bool getExchangeRate(std::string date, double& exchangeRate);
		void parseInput(std::string value);
	public :
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & copy);
		BitcoinExchange &operator=(const BitcoinExchange & rhs);
		~BitcoinExchange(void);

		void execExchange(std::string input);
};

#endif