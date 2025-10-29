#ifndef BASE_HPP

# define BASE_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime>

class Base {
	public:
		virtual ~Base();

	private:
		/*content*/
	
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif