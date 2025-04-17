#include "Zombie.hpp"

Zombie::Zombie(str name) {
	this->name = name;
	std::cout << "Zombie " << name << " appears\n";
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " disappears\n";
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}