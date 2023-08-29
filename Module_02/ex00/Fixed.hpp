#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {
	private :
		int value;
		static const int stat = 8;
	
	public :
		Fixed(void);
		Fixed(Fixed &copy);
		~Fixed(void);
		Fixed &operator=(Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif