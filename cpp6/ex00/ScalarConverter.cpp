#include "ScalarConverter.hpp"

//CONSTRUCTOR(S)
ScalarConverter::ScalarConverter() {
	std::cout << "\033[90m✿ScalarConverter constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
ScalarConverter::ScalarConverter(const ScalarConverter& to_copy) {
	std::cout << "\033[90m✿ScalarConverter copy constructor called✿\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& to_copy) {
	std::cout << "\033[90m✿ScalarConverter copy assignment operator called✿\033[0m" << std::endl;
	(void)to_copy;
	return (*this);
}

//DESTRUCTOR
ScalarConverter::~ScalarConverter() {
	std::cout << "\033[90m~ScalarConverter destructor called\033[0m" << std::endl;
}

//PUBLIC
void		ScalarConverter::convert(std::string const &literal)
{
	void (*convertFunctions[])(std::string const &literal) = { convertChar, convertInt, convertFloat,\
	 convertDouble, convertPseudoF, convertPseudo, errorLiteral};

	convertFunctions[getType(literal)](literal);
		
}

