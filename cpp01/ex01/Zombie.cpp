#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie  appears\n";
}

Zombie::~Zombie() {
	std::cout << "Zombie disappears\n";
}

void	Zombie::announce() const{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(str name) {
	this->name = name;
}