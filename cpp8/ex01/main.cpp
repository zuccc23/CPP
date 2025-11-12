#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	std::cout << std::endl << "===== Subject tests =====" << std::endl ;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "===== adding an extra value =====" << std::endl ;
	try
	{
		sp.addNumber(22);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "===== Trying 10 000 values =====" << std::endl ;
	try
	{
		Span bigSpan(10000);
		std::srand(std::time(0));

		for (int i = 0; i < 10000; ++i)
			bigSpan.addNumber(std::rand());

		std::cout << "Shortest span (10000 numbers): " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span (10000 numbers): " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== Add numbers with range =====" << std::endl ;
	std::vector<int> v;
	try
	{
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		// v.push_back(4);
		// v.push_back(5);
		// v.push_back(6);
		Span spp = Span(5);
		spp.addRange(v.begin(), v.end());
		std::cout << spp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}