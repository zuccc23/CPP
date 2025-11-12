#ifndef EASYFIND_HPP

# define EASYFIND_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

class NumberNotFoundException : public std::exception {
	const char* what() const throw() {
		return ("The number hasnt been found in the container");
	}
};

template <typename T>
typename T::const_iterator easyfind(const T& container, const int& numToFind)
{
	typename T::const_iterator iter = std::find(container.begin(), container.end(), numToFind);
	if (iter == container.end())
		throw NumberNotFoundException();
	return iter;
}

#endif