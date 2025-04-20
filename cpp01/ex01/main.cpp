#include "Zombie.hpp"

int	main() {
	Zombie	*horde = zombieHorde(5, "Walking Ted");
	delete[] horde;
	return 0;
}