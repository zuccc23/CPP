#ifndef BRAIN

# define BRAIN

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Brain {
	public:
		Brain();
		Brain(const Brain& to_copy);
		Brain& operator=(const Brain& to_copy);
		~Brain();

		void	setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;

	private:
		std::string	_ideas[100];
	
};


#endif