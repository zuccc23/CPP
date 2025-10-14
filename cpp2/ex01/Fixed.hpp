#ifndef FIXED_HPP

# define FIXED_HPP
#include <string.h>
#include <iostream>
#include <stdlib.h>

class Fixed
{
	private:
		int					numValue;
		static const int	fracBits = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed& to_copy);
		Fixed(const int num);
		Fixed(const float num);
		Fixed&	operator=(const Fixed& to_copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed);

#endif