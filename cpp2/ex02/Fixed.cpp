#include "Fixed.hpp"
#include <cmath>

//CONSTRUCTORS
Fixed::Fixed(void) : numValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : numValue(0)
{
	// std::cout << "int param constructor called" << std::endl;
	numValue = num * 256;
}

Fixed::Fixed(const float num) : numValue(0)
{
	(void)num;
	numValue = (int)roundf((num * 256));
	// std::cout << "float param constructor called" << std::endl;

}

//copies the values of a Fixed object into another one AT ASSIGNMENT when '=' is used
Fixed::Fixed(const Fixed& to_copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

//DESTRUCTOR
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

//OPERATORS
//copies the values of a Fixed object into another one AFTER ASSIGNMENT when '=' is used
Fixed&	Fixed::operator=(const Fixed& to_copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		numValue = to_copy.getRawBits();
	return (*this);
}

//COMPARISON OPERATORS
bool	Fixed::operator>(Fixed const& other) const
{
	// std::cout << "> operator called" << std::endl;
	if (numValue > other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	// std::cout << "< operator called" << std::endl;
	if (numValue < other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	// std::cout << ">= operator called" << std::endl;
	if (numValue >= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	// std::cout << "<= operator called" << std::endl;
	if (numValue <= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	// std::cout << "== operator called" << std::endl;
	if (numValue == other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	// std::cout << "!= operator called" << std::endl;
	if (numValue != other.getRawBits())
		return (true);
	else
		return (false);
}

//ARITHMETIC OPERATORS
Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed	res;

	res.numValue = numValue + other.numValue;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed	res;

	res.numValue = numValue - other.numValue;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	Fixed	res;

	res.numValue = (numValue / other.numValue) * 256;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	res;

	res.numValue = (numValue * other.numValue) / 256;
	return (res);
}

//INCREMENT OPERATORS
Fixed&	Fixed::operator++(void)
{
	numValue += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	numValue -= 1;
	return (*this);
}

// Post-increment
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	numValue += 1;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	numValue -= 1;
	return temp;
}

//MIN AND MAX FUNCTIONS
Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(Fixed const& a, Fixed const& b) 
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(Fixed const& a, Fixed const& b) 
{
	return (a > b) ? a : b;
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