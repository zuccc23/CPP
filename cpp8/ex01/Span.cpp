#include "Span.hpp"

//CONSTRUCTOR(S)
Span::Span() : _N(0) {
	std::cout << "\033[90m✿Span constructor called✿\033[0m" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	std::cout << "\033[90m✿Span constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
Span::Span(const Span& to_copy) : _N(to_copy._N) {
	(void)to_copy;
	std::cout << "\033[90m✿Span copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
Span& Span::operator=(const Span& to_copy) {
	(void)to_copy;
	std::cout << "\033[90m✿Span copy assignment operator called✿\033[0m" << std::endl;
	return (*this);
}

//DESTRUCTOR
Span::~Span() {
	std::cout << "\033[90m~Span destructor called\033[0m" << std::endl;
}

//PUBLIC
void Span::addNumber(const int newNumber)
{
	if (_numbers.size() >= _N)
		throw MaxSizeException();
	_numbers.push_back(newNumber);
}

// 3 6 9 11 17
int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw TooFewNumbersException();
	
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int finalSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); i++)
	{
		if ((sortedNumbers[i] - sortedNumbers[i-1]) < finalSpan)
			finalSpan = sortedNumbers[i] - sortedNumbers[i-1];
	}

	return finalSpan;
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw TooFewNumbersException();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

//EXCEPTIONS

const char* Span::MaxSizeException::what() const throw()
{
	return ("The maximum amount of elements has already been added");
}

const char* Span::MaxRangeException::what() const throw()
{
	return ("The range is too large to be added");
}

const char* Span::TooFewNumbersException::what() const throw()
{
	return ("There are not enough elements to find a span");
}