#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
	private :
		Contact contact[8];
		int		index;
		bool	full;
	public	:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
};

#endif