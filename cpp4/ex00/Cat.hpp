#ifndef CAT_HPP

# define CAT_HPP
#include "Animal.hpp"
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

	private:
		/*content*/
	
};

#endif