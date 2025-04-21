
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	WrongAnimal	*ddog = new WrongAnimal();
	Dog		*dog = new Dog();

	std::cout << ddog->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	ddog->makeSound();
	dog->makeSound();
	delete ddog;

	ddog = new WrongCat();
	ddog->makeSound();
	delete dog;
	delete ddog;
}