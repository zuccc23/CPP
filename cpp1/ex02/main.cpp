#include <string.h>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string address: " << &str << std::endl;
	std::cout << "string address inside ptr: " << stringPTR << std::endl;
	std::cout << "string address inside reference: " << &stringREF << std::endl;

	std::cout << "string value: " << str << std::endl;
	std::cout << "string value inside ptr: " << *stringPTR << std::endl;
	std::cout << "string value inside reference: " << stringREF << std::endl;
	return(0);
}
