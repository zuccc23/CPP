#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// if (ac < 3)
	// {
	// 	std::cerr << "Error: too few arguments to sort" << std::endl;
	// 	return (1);
	// }
	// try
	// {
	// 	PmergeMe merge;
	// 	merge.sort(ac, av);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	std::vector<int> data;
	data.push_back(9);
    data.push_back(3);
    data.push_back(7);
    data.push_back(2);
    data.push_back(10);
    data.push_back(1);

    std::vector<int> sorted;

	reducePairs(data, sorted);
	std::cout << std::endl << "--AFTER--" << std::endl;
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	
	return 0;
}

// data.push_back(6);
// 	data.push_back(9);
//     data.push_back(3);
// 	data.push_back(8);
//     data.push_back(7);
// 	data.push_back(5);
//     data.push_back(2);
//     data.push_back(10);
//     data.push_back(1);
// 	data.push_back(4);