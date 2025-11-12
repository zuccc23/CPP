#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::cout << std::endl << "===== Vector container =====" << std::endl ;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	try
	{
		std::cout << easyfind(vec, 1) - vec.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyfind(vec, 7) - vec.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "===== Deque container =====" << std::endl ;
	std::deque<int> deq;
	deq.push_back(11);
	deq.push_back(22);
	deq.push_back(33);
	try
	{
		std::cout << easyfind(deq, 22) - deq.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyfind(deq, 44) - deq.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "===== List container =====" << std::endl ;
	std::list<int> lilist;
	lilist.push_back(111);
	lilist.push_back(222);
	lilist.push_back(333);
	try
	{
		std::list<int>::const_iterator iter = easyfind(lilist, 333);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::const_iterator iter = easyfind(lilist, 444);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}