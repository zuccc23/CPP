#ifndef ANIMAL_HPP

# define ANIMAL_HPP
#include <string.h>
#include <iostream>
#include <stdlib.h>

class Animal {
	public:
		Animal();
		Animal(const Animal& to_copy);
		Animal& operator=(const Animal& to_copy);
		~Animal();

		std::string	getType();
		void	setType(Animal animal);

	protected:
		std::string _type;
	
};

#endif