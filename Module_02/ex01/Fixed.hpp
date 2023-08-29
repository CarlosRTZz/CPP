#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {
	private :
		int value;
		static const int _bit = 8;
	
	public :
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed &operator=(const Fixed &fixed);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
		std::ostream &operator<<(std::ostream & o, const Fixed &fixed);

#endif