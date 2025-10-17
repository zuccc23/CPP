#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP
#include <string.h>
#include <iostream>
#include <stdlib.h>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& to_copy);
		WrongAnimal& operator=(const WrongAnimal& to_copy);
		virtual ~WrongAnimal();

		std::string	getType() const;
		virtual void	makeSound(void) const;

	protected:
		std::string _type;
	
};

#endif