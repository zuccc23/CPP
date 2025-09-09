#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook instance(23);
	std::cout << "in main: "  << instance.numm << std::endl;
	Contact	contact;

	contact.nickname = "helo";

}