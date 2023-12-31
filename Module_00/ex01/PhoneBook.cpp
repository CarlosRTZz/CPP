#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() {
	this->index = 0;
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}

bool	hasDigit(std::string str) {
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::displayContact(int index) {
	std::cout << "First Name : " << this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname : " << this->contact[index].getNickname() << std::endl;
	std::cout << "Number : " << this->contact[index].getNumber() << std::endl;
	std::cout << "Secret : " << this->contact[index].getSecret() << std::endl;
}

std::string displayStr(std::string str) {
	std::string str2;

	if (str.size() > 10)
	{
		str2 = str.substr(0,9);
		str2 += ".";
		return str2;
	}
	return str;
}

void	PhoneBook::add() {
	std::string firstName, lastName, nickname, strnumber, secret;

	while (firstName.empty()) {
		std::cout << "[Add first name]" << std::endl;
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit (0);
	}

	while (lastName.empty()) {
		std::cout << "[Add last name]" << std::endl;
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit (0);
	}

	while (nickname.empty()) {
		std::cout << "[Add nickname]" << std::endl;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit (0);
	}

	while (strnumber.empty()) {
		std::cout << "[Add number]" << std::endl;
		std::getline(std::cin, strnumber);
		if (std::cin.eof())
			exit (0);
		if (!hasDigit(strnumber))
			strnumber.clear();
	}

	while (secret.empty()) {
		std::cout << "[Add secret]" << std::endl;
		std::getline(std::cin, secret);
		if (std::cin.eof())
			exit (0);
	}

	this->contact[this->index].setFirstName(firstName);
	this->contact[this->index].setLastName(lastName);
	this->contact[this->index].setNickname(nickname);
	this->contact[this->index].setNumber(strnumber);
	this->contact[this->index].setSecret(secret);
	index++;
	if (index == 8)
		index = 0;
}

void PhoneBook::search() {
	std::string str;

	if (this->contact[0].getFirstName().empty()) {
		std::cout << "There are no contacts yet" << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		if (this->contact[i].getFirstName().empty())
			break ;
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << displayStr(this->contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << displayStr(this->contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << displayStr(this->contact[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "Type a index to find" << std::endl;
	std::getline(std::cin, str);
	std::stringstream ss(str);
	long nb;
	ss >> nb;
	if (str.empty() || !hasDigit(str) || (nb < 0 || nb > 7) || this->contact[nb].getFirstName().empty())
		std::cout << "Please provide a valid index" << std::endl;
	else
		displayContact(nb);
}
