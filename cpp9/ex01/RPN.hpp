#ifndef RPN_HPP

# define RPN_HPP

#include <string.h>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class RPN {
	public:
		RPN();
		RPN(const RPN& to_copy);
		RPN& operator=(const RPN& to_copy);
		~RPN();

		int	calculate(const std::string& expression);

	private:
		std::stack<int> _stack;

		bool	isNumber(std::string const &token);
		bool	isOperator(std::string const &token);
		int		doOperation(int a, int b, char oper);
	
};



#endif