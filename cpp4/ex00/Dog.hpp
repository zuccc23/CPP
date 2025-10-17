#ifndef DOG_HPP

# define DOG_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog& to_copy);
		Dog& operator=(const Dog& to_copy);
		~Dog();

		void	makeSound() const;

	private:
		/*content*/
	
};



#endif