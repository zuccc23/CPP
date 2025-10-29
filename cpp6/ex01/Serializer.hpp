#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>

struct Data;

class Serializer {
	public:
		
		Serializer(const Serializer& to_copy);
		Serializer& operator=(const Serializer& to_copy);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
	
};


#endif