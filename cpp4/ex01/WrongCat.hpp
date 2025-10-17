#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& to_copy);
		WrongCat& operator=(const WrongCat& to_copy);
		~WrongCat();

		void	makeSound(void) const;

	private:
		/*content*/
	
};

#endif