
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main() {
	Cat		max;
	Dog		jax;

	std::cout << max.getType() << " " << std::endl;
	std::cout << jax.getType() << " " << std::endl;

	jax.makeSound();
	max.think();
	jax.think();

	return 0;
}
