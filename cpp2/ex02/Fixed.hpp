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
		Fixed();
		Fixed(const Fixed& to_copy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);

		Fixed&	operator=(const Fixed& to_copy);
		bool	operator>(Fixed const& other)const;
		bool	operator<(const Fixed& other)const;
		bool	operator>=(const Fixed& other)const;
		bool	operator<=(const Fixed& other)const;
		bool	operator==(const Fixed& other)const;
		bool	operator!=(const Fixed& other)const;

		Fixed	operator+(const Fixed& other);
		Fixed	operator/(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator-(const Fixed& other);

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed);

#endif