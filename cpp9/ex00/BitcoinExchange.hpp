#ifndef BITCOINEXCHANGE_HPP

# define BITCOINEXCHANGE_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& to_copy);
		BitcoinExchange& operator=(const BitcoinExchange& to_copy);
		~BitcoinExchange();

		void fillDatabase(const std::string& filename);
		void processInputValues(const std::string& filename);


	private:
		std::map<std::string, float> _database;
		int isValidDate(const std::string& date);
		float findClosestPrice(const std::string& date);
		void printClosestPrice(const std::string& date);

	
};

bool	isNumber(std::string const &date);

#define SUCCESS 0
#define ERROR 1
#define TOO_EARLY 2
#define INEXISTANT 3

#endif