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
		Fixed&	operator=(const Fixed& to_copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};



#endif