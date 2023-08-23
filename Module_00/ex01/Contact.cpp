#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

std::string	Contact::getFirstName(void) {
	return (firstName);
}

void	Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

std::string	Contact::getLastName(void) {
	return (lastName);
}

void	Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

std::string	Contact::getNickname(void) {
	return (nickname);
}

void	Contact::setNumber(std::string number) {
	this->number = number;
}

std::string Contact::getNumber(void) {
	return (number);
}

void	Contact::setSecret(std::string secret) {
	this->secret = secret;
}

std::string	Contact::getSecret(void) {
	return (secret);
}