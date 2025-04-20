#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	hussein("hussein");
	ClapTrap	*ali = new ClapTrap("ali");
	ScavTrap	mark("mark");

	hussein.attack("mark");
	mark.takeDamage(hussein.getAttackDamage());
	mark.beRepaired(18);
	mark.guardGate();
	mark.attack("ali");
	ali->takeDamage(mark.getAttackDamage());
	delete ali;
	return 0;
}

