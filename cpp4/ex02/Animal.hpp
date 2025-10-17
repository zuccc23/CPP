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
		virtual ~Animal();

		std::string	getType() const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string _type;
	
};

#endif