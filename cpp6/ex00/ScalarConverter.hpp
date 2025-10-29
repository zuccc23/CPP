#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "utils.hpp"


class ScalarConverter {
	public:
		ScalarConverter(const ScalarConverter& to_copy);
		ScalarConverter& operator=(const ScalarConverter& to_copy);
		~ScalarConverter();
		
		static void		convert(std::string const &literal);

	private:
		ScalarConverter();

	
};

#endif