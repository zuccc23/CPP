
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Serializer.hpp"
#include "Data.hpp"

int main (void)
{
	Data data;
	Data* dataPtr = &data;
	uintptr_t serializedNum;

	dataPtr->num = 42;
	dataPtr->str = "testytest";
	serializedNum = Serializer::serialize(dataPtr);

	std::cout << std::endl << "===== Original pointer =====" << std::endl ;
	std::cout << dataPtr << std::endl;
	std::cout << std::endl << "===== Serialized pointer =====" << std::endl ;
	std::cout << serializedNum << std::endl;
	std::cout << std::endl << "===== Deserialized pointer =====" << std::endl ;
	std::cout << Serializer::deserialize(serializedNum) << std::endl;

	std::cout << std::endl << "===== Accessing data through original pointer =====" << std::endl ;
	std::cout << dataPtr->num << std::endl << dataPtr->str << std::endl;

	std::cout << std::endl << "===== Accessing data through serialized/deserialized pointer =====" << std::endl ;
	Data *newPtr = Serializer::deserialize(serializedNum);
	std::cout << newPtr->num << std::endl << newPtr->str << std::endl;

	return(0);
}