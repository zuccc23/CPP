#ifndef CAT_HPP

# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& to_copy);
		Cat& operator=(const Cat& to_copy);
		~Cat();

		void	makeSound(void) const;
		void	setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;

	private:
		Brain	*_brain;
	
};

#endif