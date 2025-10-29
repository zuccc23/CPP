#ifndef UTILS_HPP

# define UTILS_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <climits>

//PARSING
int		checkFlow(std::string const &literal, int type);
bool	isPseudoLiteralFloat(std::string const &literal);
bool	isPseudoLiteralDouble(std::string const &literal);
int		getType(std::string const &literal);
bool	isInt(std::string const &literal);
bool	isDouble(std::string const &literal);
bool	isFloat(std::string const &literal);
bool	checkSpecialCharacters(std::string const &literal);
bool	checkNumber(std::string const &literal);

//CONVERT
void	convertInt(std::string const &literal);
void	convertChar(std::string const &literal);
void	convertDouble(std::string const &literal);
void	convertFloat(std::string const &literal);
void	convertPseudoF(std::string const &literal);
void	convertPseudo(std::string const &literal);
void	errorLiteral(std::string const &literal);

# define CHAR_TYPE 0
# define INT_TYPE 1
# define FLOAT_TYPE 2
# define DOUBLE_TYPE 3
# define FLOAT_LIT 4
# define DOUBLE_LIT 5
# define NO_TYPE 6

#endif

