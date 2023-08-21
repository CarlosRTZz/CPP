#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact {
	private :
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	number;
		std::string secret;
	public :
		void setFirstName(std::string firstName);
		std::string getFirstName(void);

		void setLastName(std::string lastName);
		std::string getLastName(void);

		void setNickname(std::string nickname);
		std::string getNickname(void);

		void setNumber(std::string number);
		std::string getNumber(void);

		void setSecret(std::string secret);
		std::string getSecret(void);
		
		Contact(void);
		~Contact(void);
};

#endif