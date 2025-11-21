#include "RPN.hpp"

//CONSTRUCTOR(S)
RPN::RPN() {
	std::cout << "\033[90m✿RPN constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
RPN::RPN(const RPN& to_copy) : _stack(to_copy._stack) {
	std::cout << "\033[90m✿RPN copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
RPN& RPN::operator=(const RPN& to_copy) {
	std::cout << "\033[90m✿RPN copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_stack = to_copy._stack;
	}
	return (*this);
}

//DESTRUCTOR
RPN::~RPN() {
	std::cout << "\033[90m~RPN destructor called\033[0m" << std::endl;
}

//PUBLIC
int	RPN::calculate(const std::string& expression)
{
	std::string token;
	std::istringstream inputStream(expression);

	while (inputStream >> token)
	{
		if (isNumber(token) == true)
			_stack.push(atoi(token.c_str()));
		else if (isOperator(token) == true)
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: wrong notation");

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = doOperation(a, b, token[0]);
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error: wrong element(s): only numbers(0-9) and operands(+-*/) allowed");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: wrong notation");
	return _stack.top();
}


//PRIVATE

int		RPN::doOperation(int a, int b, char oper)
{
	switch (oper)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by 0");
			return a / b;
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

bool	RPN::isNumber(std::string const &token)
{
	if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		return true;
	if (token.size() == 2 && std::isdigit(static_cast<unsigned char>(token[1])) && (token[0] == '-' || token[0] == '+'))
		return true;
	return false;
}

bool	RPN::isOperator(std::string const &token)
{
	if (token.size() != 1)
		return false;
	
	if (token[0] == '+' || token[0] == '*' || token[0] =='-' || token[0] == '/')
		return true;
	
	return false;
}