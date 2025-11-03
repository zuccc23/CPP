#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{

	// int * intArray = new int[3];
	// intArray[0] = 1;
	// std::cout << intArray[0] << std::endl;
	
	//TEST COPIES!!!!
	// Array<int> intArray(5);
	// Array<int> secondintArray(intArray);
	// std::cout << intArray.size() << std::endl;

	// try
	// {
	// 	secondintArray[4] = 9;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// intArray[0] = 7;
	
	// std::cout << intArray[0] << std::endl;
	// std::cout << secondintArray[0] << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
	    const int value = rand();
	    numbers[i] = value;
	    mirror[i] = value;
	}
	//SCOPE
	{
	    Array<int> tmp = numbers;
	    Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
	    if (mirror[i] != numbers[i])
	    {
	        std::cerr << "didn't save the same value!!" << std::endl;
	        return 1;
	    }
	}
	try
	{
	    numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}
	try
	{
	    numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
	    numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}