#include "Serializer.hpp"

//CONSTRUCTOR(S)
Serializer::Serializer() {
	std::cout << "\033[90m✿Serializer constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
Serializer::Serializer(const Serializer& to_copy) {
	std::cout << "\033[90m✿Serializer copy constructor called✿\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Serializer& Serializer::operator=(const Serializer& to_copy) {
	std::cout << "\033[90m✿Serializer copy assignment operator called✿\033[0m" << std::endl;
	(void)to_copy;
	return (*this);
}

//DESTRUCTOR
Serializer::~Serializer() {
	std::cout << "\033[90m~Serializer destructor called\033[0m" << std::endl;
}

//PUBLIC
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dataPtr;

	dataPtr = reinterpret_cast<Data *>(raw);
	return (dataPtr);
}