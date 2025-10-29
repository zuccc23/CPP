
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main (void)
{
	Base* test = generate();
	identify(test);
	identify(*test);
	delete test;
	return(0);
}