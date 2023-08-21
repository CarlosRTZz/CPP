#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() {
	this->index = 0;
	this->full = false;
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
}

void PhoneBook::search() {
	std::string str;

	if (!this->full && this->index == 0)
	{
		std::cout << "There are no contacts yet" << std::endl;
		return ;
	}
	for (int i = 0; i < this->index || (this->full && i < 8); i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << this->contact[i].getFirstName() << "|";
		std::cout << std::setw(10);
		std::cout << this->contact[i].getLastName() << "|";
		std::cout << std::setw(10);
		std::cout << this->contact[i].getNickname() << "|" << std::endl;
	}
	std::cout << "Type un truc sale chien!!!!!" << std::endl;
	std::getline(std::cin, str);
	if (!str.empty() && hasDigit(str))
	{
		std::cout << "bien ouej" << std::endl;
	}
	else
		std::cout << "only digit between 0 and 8" << std::endl;
}
