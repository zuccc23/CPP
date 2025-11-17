#include "BitcoinExchange.hpp"

//CONSTRUCTOR(S)
BitcoinExchange::BitcoinExchange() {
	std::cout << "\033[90m✿BitcoinExchange constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy) : _database(to_copy._database) {
	std::cout << "\033[90m✿BitcoinExchange copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& to_copy) {
	std::cout << "\033[90m✿BitcoinExchange copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_database = to_copy._database;
	}
	return (*this);
}

//DESTRUCTOR
BitcoinExchange::~BitcoinExchange() {
	std::cout << "\033[90m~BitcoinExchange destructor called\033[0m" << std::endl;
}

//PUBLIC
void BitcoinExchange::fillDatabase(const std::string& filename) {
	std::ifstream dataFile(filename.c_str());
	if (!dataFile.is_open())
		throw std::runtime_error("Error: could not open file");
	
	std::string line;
	std::getline(dataFile, line);

	while (std::getline(dataFile, line))
	{
		size_t delimiter = line.find(',');
		std::string date = line.substr(0, delimiter);
		float price = atof(line.substr(delimiter+1).c_str());

		_database[date] = price;
	}
	// std::cout << _database["2010-08-20"] << std::endl;
}

void BitcoinExchange::processInputValues(const std::string& filename)
{
	
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(inputFile, line);


	if (isValidDate("2009-02-01") != SUCCESS)
	 	throw std::runtime_error("Error: expected date format: YYYY-MM-DD");
	findClosestPrice("2012-12-29");
}

//PRIVATE
int BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return ERROR;
	if (isNumber(date.substr(0, 4)) == false)
		return ERROR;
	if (isNumber(date.substr(5, 2)) == false)
		return ERROR;
	if (isNumber(date.substr(8, 2)) == false)
		return ERROR;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month > 12 || month < 1)
		return false;
	if (day > 31 || day < 1)
		return false;

	return true;
}

float BitcoinExchange::findClosestPrice(const std::string& date) {
	std::map<std::string, float>::iterator iter = _database.upper_bound(date);
	if (iter == _database.begin())
    	throw std::runtime_error("Error: date too early");
	--iter;
	// std::cout << iter->first << std::endl;
	return (iter->second);
}

//NON MEMBER
bool	isNumber(std::string const &date)
{
	for (int i = 0; (size_t)i < date.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	return true;
}