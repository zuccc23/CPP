#include <iostream>
#include <algorithm>

int main(int argc, char **argv) {
	std::string	temp;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		temp = argv[i];
		std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		std::cout << temp;
	}
	std::cout << "\n";
	return 0;
}
