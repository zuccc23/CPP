#ifndef ITER_HPP

# define ITER_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

template <typename T, typename F>
void iter(T* array, int const length, F function)
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

// template <typename T>
// void	printStuff(T toPrint)
// {
// 	std::cout << toPrint << std::endl;
// }

#endif