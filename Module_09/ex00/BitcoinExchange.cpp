#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::ifstream file("data.csv");
	if (!file.isopen()) {
		std::cout << "Error: file not found" << std::endl;
		this->readFlag = 0;
		return ;
	}
	std::string line = std::getline(file, line);
	if (line != "date,exchange_rate") {
		std::cout << "Database wrong format!" << std::endl;
		return
	}
	while (std::getline(file, line)) {
		
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) {
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & rhs) {
	if (this != &rhs)
		this->_dataMap = rhs._dataMap;
		return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {

}

bool BitcoinExchange::checkDate(std::string date) {
	
}