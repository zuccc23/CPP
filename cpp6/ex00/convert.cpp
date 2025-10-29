#include "utils.hpp"

void	convertInt(std::string const &literal)
{
	int	value = 0;

	value = std::atoi(literal.c_str());
	if (std::isprint(value))
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char: " << "non displayable" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	convertChar(std::string const &literal)
{
	char	value = literal[0];

	std::cout << "char: " << value << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	convertDouble(std::string const &literal)
{
	double	value = atof(literal.c_str());

	if (value > INT_MAX || value < INT_MIN)
		std::cout << "char: " << "non displayable" << std::endl << "int: " << "impossible" << std::endl;
	else
	{
		if (std::isprint(static_cast<int>(value)))
			std::cout << "char: " << static_cast<char>(value) << std::endl ;
		else
			std::cout << "char: " << "non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	if (value > __FLT_MAX__ || value < -__FLT_MAX__)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	convertFloat(std::string const &literal)
{
	float	value = std::atof(literal.c_str());

	if (value > INT_MAX || value < INT_MIN)
		std::cout << "char: " << "non displayable" << std::endl << "int: " << "impossible" << std::endl;
	else
	{
		if (std::isprint(static_cast<int>(value)))
			std::cout << "char: " << static_cast<char>(value) << std::endl ;
		else
			std::cout << "char: " << "non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	convertPseudo(std::string const &literal)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void	convertPseudoF(std::string const &literal)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
}

void	errorLiteral(std::string const &literal)
{
	std::cout << "Error: " << literal << " is not a correct literal expression" << std::endl;
}