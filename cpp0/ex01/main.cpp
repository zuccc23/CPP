#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

int	main(void)
{
	std::string buff;
	PhoneBook phonebook;

	std::cout << "-----IN MAIN-----" << std::endl;
	
	// phonebook.show_contact();
	// while (1)
	// {
	// 	if ()
	// }
	// std::cin >> buff;
	// std::cout << buff << std::endl;
	// std::cin >> buff;
	// std::cout << buff << std::endl;
	phonebook.display_contact_list();
	std::cout << "-----END OF PROGRAM-----" << std::endl;
}