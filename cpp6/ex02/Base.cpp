#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//DESTRUCTOR
Base::~Base() {
	std::cout << "\033[90m~Base destructor called\033[0m" << std::endl;
}

//PUBLIC

//NON MEMBER

Base* generate(void)
{
	srand(time(0));
	int num = rand() % 3;
	
	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "object type: A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "object type: B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "object type: C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "object type: A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "object type: B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "object type: C" << std::endl;
		return;

	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	
}
