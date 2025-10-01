#include "Fixed.hpp"

Fixed::Fixed(void) : numValue(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (numValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	numValue = raw;
}
