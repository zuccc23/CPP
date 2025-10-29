#include "utils.hpp"

int	checkFlow(std::string const &literal, int type)
{
	if (type == INT_TYPE && literal.size() > 11)
		return (false);
	long checkSize = std::atol(literal.c_str());
	if (checkSize > INT_MAX || checkSize < INT_MIN)
		return false;
	
	return (0);
}

int	getType(std::string const &literal)
{
	if (literal == "")
		return NO_TYPE;
	if (literal.size() == 1 && std::isalpha(literal[0]))
		return CHAR_TYPE;
	if (isPseudoLiteralDouble(literal) == true)
		return DOUBLE_LIT;
	if (isPseudoLiteralFloat(literal) == true)
		return FLOAT_LIT;
	if (isInt(literal) == true)
		return INT_TYPE;
	if (checkSpecialCharacters(literal) == false)
		return NO_TYPE;
	if (isDouble(literal) == true)
		return DOUBLE_TYPE;
	if (isFloat(literal) == true)
		return FLOAT_TYPE;
	else
		return NO_TYPE;
}

bool	checkNumber(std::string const &literal)
{
	int n = 0;

	for (int i = 0; (size_t)i < literal.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(literal[i])))
			n++;
	}
	if (n == 0)
		return false;
	return true;
}

bool	checkSpecialCharacters(std::string const &literal)
{
	int	dot = 0;
	int	f = 0;

	if (literal == "+" || literal == "-" || literal == ".")
		return false;

	for (int i = 0; (size_t)i < literal.size(); i++)
	{
		if (literal[i] == '.')
			dot++;
		if (literal[i] == 'f' || literal[i] == 'F')
			f++;
	}
	if (dot != 1 || f > 1)
		return false;
	return true;
}

bool	isDouble(std::string const &literal)
{
	if (checkNumber(literal) == false)
		return false;
	for (int i = 0; (size_t)i < literal.size(); i++)
	{
		if (literal[0] == '+' || literal[0] == '-')
		i++;
		if (literal[i] == '.')
			i++;
		if (literal[i] && !std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return true;
}

bool	isFloat(std::string const &literal)
{
	if (checkNumber(literal) == false)
		return false;
	if (literal[literal.size() - 1] != 'f' && literal[literal.size() - 1] != 'F')
		return false;
	for (int i = 0; (size_t)i < literal.size() - 1; i++)
	{
		if (literal[0] == '+' || literal[0] == '-')
		i++;
		if (literal[i+1] && literal[i] == '.')
			i++;
		if (literal[i] && literal[i+1] && !std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return true;
}

bool	isInt(std::string const &literal)
{
	if (checkNumber(literal) == false)
		return false;
	for (int i = 0; (size_t)i < literal.size(); i++)
	{
		if (literal[0] == '+' || literal[0] == '-')
			i++;
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return true;
}

bool	isPseudoLiteralFloat(std::string const &literal)
{
	if (literal == "+inff")
		return true;
	else if (literal == "-inff")
		return true;
	else if (literal == "nanf")
		return true;
	else
		return false;
}

bool	isPseudoLiteralDouble(std::string const &literal)
{
	if (literal == "-inf")
		return true;
	else if (literal == "+inf")
		return true;
	else if (literal == "nan")
		return true;
	else
		return false;
}