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
	Animal froggy;
	Cat	minoushka;
	Dog	pompom;
	WrongAnimal	yeti;
	WrongCat	paminou;

	std::cout << std::endl << "===== Tests =====" << std::endl;
	// std::cout << test.getType() << std::endl;
	froggy.makeSound();
	minoushka.makeSound();
	pompom.makeSound();

	std::cout << std::endl << "===== Copy Tests =====" << std::endl;
	Cat copyCat = minoushka;

	

	std::cout << std::endl << "===== Wrong animals =====" << std::endl;
	yeti.makeSound();
	paminou.makeSound();

	std::cout << std::endl << "===== Making subject objects =====" << std::endl ;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << std::endl << "===== Subject Tests =====" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wcat->makeSound();

	std::cout << std::endl << "===== Destructors =====" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wcat;
	
	return(0);
}