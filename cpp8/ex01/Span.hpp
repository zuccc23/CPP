#ifndef SPAN_HPP

# define SPAN_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& to_copy);
		Span& operator=(const Span& to_copy);
		~Span();

		void addNumber(const int newNumber);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (_numbers.size() + std::distance(begin, end) > _N)
				throw MaxRangeException();
			_numbers.insert(_numbers.end(), begin, end);
		}


		class MaxSizeException : public std::exception {
			const char* what() const throw();
		};
		class MaxRangeException : public std::exception {
			const char* what() const throw();
		};
		class TooFewNumbersException : public std::exception {
			const char* what() const throw();
		};

	private:
		const unsigned int _N;
		std::vector<int> _numbers;
};


#endif