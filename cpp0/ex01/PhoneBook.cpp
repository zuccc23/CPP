#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook(int num) : numm(num)
{
	std::cout << "constructor" << std::endl;
	this->test();
}

PhoneBook::~PhoneBook()
{
	std::cout << "destructor" << std::endl;
}

void	PhoneBook::test(void)
{
	std::cout << "test function" << std::endl;
}