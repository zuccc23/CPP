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
}

void BitcoinExchange::processInputValues(const std::string& filename)
{
	
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open file");
	
	std::string line; //maybe check if theres no line
	std::getline(inputFile, line);
	if (line != "date | value")
		std::cout << "STOPP" << std::endl;

	while (std::getline(inputFile, line))
	{
		//----------GET DATE-------------
		size_t pipe_pos = line.find('|');
		
		if (pipe_pos == std::string::npos) {
			std::cerr << "Error: bad input1 => " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pipe_pos);
		date.erase(date.find_last_not_of(" \t") + 1);
		
		// ---------VALIDATE DATE------------
		if (isValidDate(date) == false) {
			std::cerr << "Error: bad input2 => " << date << std::endl;
			continue;
		}

		// ---------GET VALUE------------
		std::string value_str = line.substr(pipe_pos + 1);
		value_str.erase(0, value_str.find_first_not_of(" \t"));
		// --------------CONVERT VALUE-----------
		char* endptr;
		float value = strtof(value_str.c_str(), &endptr);
		
		if (*endptr != '\0' && *endptr != '\n') {
			std::cerr << "Error: bad input3 => " << line << std::endl;
			continue;
		}
		// ---------VALIDATE VALUE--------
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		//---------------GET PRICE----------------
		try {
			float price = findClosestPrice(date);
			std::cout << "\033[38;5;217mDate: \033[0m" << date << "\033[38;5;217m Bitcoins: \033[0m" << value << "\033[38;5;217m => \033[0m" << (value * price) << " ";
			printClosestPrice(date);
			std::cout << std::endl;
		} 
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

//PRIVATE
int BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if (isNumber(date.substr(0, 4)) == false)
		return false;
	if (isNumber(date.substr(5, 2)) == false)
		return false;
	if (isNumber(date.substr(8, 2)) == false)
		return false;

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
	return (iter->second);
}

void BitcoinExchange::printClosestPrice(const std::string& date) {
	std::map<std::string, float>::iterator iter = _database.upper_bound(date);
	if (iter == _database.begin())
    	return;
	--iter;
	std::cout << "\033[90m\t" << iter->second << " (" << iter->first << ")\033[0m";
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