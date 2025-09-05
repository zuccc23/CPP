#include <iostream>
#include <stdio.h>
// using namespace std;

namespace	TestSpace{
	int	num_var = 1;
}

namespace	SecondTestSpace{
	int	num_var = 3;
}

int main() {
	// std::cout << "Test 1: \n";
	printf("Test 1: %d\n", TestSpace::num_var);
	printf("Test 2: %d\n", SecondTestSpace::num_var);
	return 0;
}