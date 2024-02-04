#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Error : data.csv : file not found");
	}
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Database Error : wrong format header");
	}
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (std::getline(iss, date, ',')) {
			if (!this->validDate(date)) {
				throw std::runtime_error("Database Error : wrong date");
			}
		} else {
			throw std::runtime_error("Database Error : wrong format");
		}
		if (std::getline(iss, valueStr)) {
			if (!this->validValue(valueStr)) {
				throw std::runtime_error("Database Error : wrong value");
			}
		} else {
			throw std::runtime_error("Database Error : wrong format");
		}
		this->_dataMap[date] = std::strtod(valueStr.c_str(), NULL);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & rhs) {
	if (this != &rhs)
		this->_dataMap = rhs._dataMap;
		return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {

}

void BitcoinExchange::trimRight(std::string& toTrim) {
	size_t lastWpIndex = toTrim.find_last_not_of(" \t\n\r\f\v");

    if (lastWpIndex != std::string::npos) {
        toTrim.erase(lastWpIndex + 1);
    } else {
        toTrim.clear();
    }
}

void BitcoinExchange::trimLeft(std::string& toTrim) {
	size_t firstNoWpIndex = toTrim.find_first_not_of(" \t\n\r\f\v");

	if (firstNoWpIndex != std::string::npos) {
		toTrim.erase(0, firstNoWpIndex);
	} else {
		toTrim.clear();
	}
}

bool BitcoinExchange::onlyDigit(std::string value) {
	for (size_t i = 0; i < value.size(); i++) {
		if (!std::isdigit(value[i]))
			return (0);
	}
	return (1);
}

bool BitcoinExchange::isValidDateRange(int year, int month, int day) {
	switch (month)
	{
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day < 1 || day > 31)
				return (0);
			break ;
        case 4: case 6: case 9: case 11:
            if (day < 1 || day > 30)
				return (0);
			break ;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (day < 1 || day > 29)
					return (0);
            } else {
				if (day < 1 || day > 28)
					return (0);
            }
			break ;
        default:
            return 0;
    }
	return (1);
}

bool BitcoinExchange::validDate(std::string date) {
	if (date.size() != 10) {
		return 0;
	}
	if (date[4] != '-' || date[7] != '-') {
		return 0;
	}
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	if (!this->onlyDigit(yearStr) || !this->onlyDigit(monthStr) || !this->onlyDigit(dayStr)) {
		return 0;
	}
	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());
	if (!this->isValidDateRange(year, month, day)) {
		return 0;
	}
	return 1;
}

bool BitcoinExchange::validValue(std::string value) {
	int has_point = 0;
	size_t lastIndex = value.size() - 1;
	for (size_t i = 0; i <= lastIndex; i++) {
		if (value[i] == '.' && has_point == 1)
			return (0);
		if (!std::isdigit(value[i]) && value[i] != '.')
			return (0);
		if (value[i] == '.') {
			has_point = 1;
			if (value[lastIndex - 1] != '.' && value[lastIndex - 2] != '.')
				return (0);
		}
	}
	return (1);
}

bool BitcoinExchange::validValueInput(std::string value) {
	int has_point = 0;
	size_t lastIndex = value.size() - 1;
	for (size_t i = 0; i <= lastIndex; i++) {
		if (value[i] == '.' && has_point == 1)
			return (0);
		if (!std::isdigit(value[i]) && value[i] != '.')
			return (0);
		if (value[i] == '.') {
			has_point = 1;
		}
	}
	return (1);
}

bool BitcoinExchange::checkValue(std::string valueStr, double& value) {
	if (valueStr.empty()) {
		std::cout << "Error: no number." << std::endl;
		return (0);
	}
	if (valueStr[0] == '-') {
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	if (!validValueInput(valueStr)) {
		std::cout << "Error: value wrong format." << std::endl;
		return (0);
	}
	value = std::strtod(valueStr.c_str(), NULL);
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

bool BitcoinExchange::getExchangeRate(std::string& date, double& exchangeRate) {
	std::map<std::string, double>::iterator it = this->_dataMap.lower_bound(date);
	if (it == this->_dataMap.end()) {
		it--;
		if (this->_dataMap.empty()) {
			std::cout << "Error: database is empty." << std::endl;
			return (0);
		}
	} else if (it->first != date) {
		if (it == this->_dataMap.begin()) {
			std::cout << "Error: date too low in relation to database!" << std::endl;
			return (0);
		}
		it--;
	}
	date = it->first;
	exchangeRate = it->second;
	return (1);
}

void BitcoinExchange::parseInput(std::string input) {
	std::ifstream file(input);
	if (!file.is_open()) {
		std::cout << "Error: " << input << " : file not found" << std::endl;
		return ;
	}
	double value;
	double exchangeRate;
	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		std::cout << "Error: first line must be [date | value] is => [" << line << "]" << std::endl;
		return ;
	}
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (std::getline(iss, date, '|')) {
			this->trimRight(date);
			if (!this->validDate(date)) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue ;
			}
		} else {
			std::cout << "Error: empty line" << std::endl;
			continue ;
		}
		if (std::getline(iss, valueStr)) {
			this->trimLeft(valueStr);
			if (!this->checkValue(valueStr, value))
				continue ;
		} else {
			std::cout << "Error: no value" << std::endl;
			continue ;
		}
		if (!this->getExchangeRate(date, exchangeRate))
			continue ;
		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
	}
}

void BitcoinExchange::execExchange(std::string input) {
	this->parseInput(input);
}