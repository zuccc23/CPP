#ifndef PMERGEME_H

# define PMERGEME_H

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& to_copy);
		PmergeMe& operator=(const PmergeMe& to_copy);
		~PmergeMe();

		//main function
		void	sort(int ac, char** av);

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		//parsing
		void	parseInput(int ac, char **av);
		bool	isInt(std::string const &input);

		//sorting
		int 	binarySearchLimited(const std::vector<int> &chain, int value, int limitIndex);
		void 	fordJohnsonVector(std::vector<int> &arr);
	
};

void reducePairs(const std::vector<int> &input, std::vector<int> &result);

#endif