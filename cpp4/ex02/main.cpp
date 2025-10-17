#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "===== Making objects =====" << std::endl ;
	Animal *zoo[10];
	for (int i = 0; i < 5; i++)
	{
		zoo[i] = new Dog();
		std::cout << "----\n";
	}
	for (int i = 5; i < 10; i++)
	{
		zoo[i] = new Cat();
		std::cout << "----\n";
	}

	std::cout << std::endl << "===== Sound Tests =====" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		zoo[i]->makeSound();
	}

	std::cout << std::endl << "===== Making objects =====" << std::endl ;
	Dog	pompom;
	Cat	mina;
	Dog	woofy;

	std::cout << std::endl << "===== Ideas Tests =====" << std::endl;
	pompom.setIdea("eat brocoli", 0);
	mina.setIdea("eat lasagna", 0);
	woofy.setIdea("eat the world", 0);
	
	std::cout << pompom.getIdea(0) << std::endl;
	std::cout << mina.getIdea(0) << std::endl;
	std::cout << woofy.getIdea(0) << std::endl;

	std::cout << std::endl << "===== Copy Tests =====" << std::endl;
	Cat copyCat = mina;

	std::cout << copyCat.getIdea(0) << std::endl;

	copyCat.setIdea("eat potatoes", 0);
	std::cout << copyCat.getIdea(0) << std::endl;
	std::cout << mina.getIdea(0) << std::endl;

	mina = copyCat;

	std::cout << std::endl << "===== Making subject objects =====" << std::endl ;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "===== Destructors =====" << std::endl;
	for (int i = 0; i < 10; i++)
		delete zoo[i];

	delete j;
	delete i;
	
	return(0);
}