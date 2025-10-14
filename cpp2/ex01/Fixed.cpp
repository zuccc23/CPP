#include "Fixed.hpp"
#include <cmath>

//CONSTRUCTORS
Fixed::Fixed(void) : numValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : numValue(0)
{
	std::cout << "int param constructor called" << std::endl;
	numValue = num * 256;
}

Fixed::Fixed(const float num) : numValue(0)
{
	numValue = (int)roundf((num * 256));
	std::cout << "float param constructor called" << std::endl;
}

//copies the values of a Fixed object into another one AT ASSIGNMENT when '=' is used
Fixed::Fixed(const Fixed& to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

//copies the values of a Fixed object into another one AFTER ASSIGNMENT when '=' is used
Fixed&	Fixed::operator=(const Fixed& to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		numValue = to_copy.getRawBits();
	return (*this);
}

//DESTRUCTOR
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//PUBLIC
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (numValue);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	numValue = raw;
}

float Fixed::toFloat( void ) const
{
	return((float) numValue / 256.0f);
}

int Fixed::toInt( void ) const
{
	return(numValue / 256);
}

//NON MEMBER
std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed)
{
	output_stream << fixed.toFloat();
	return (output_stream);
}