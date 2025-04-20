#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap	hussein("hussein");
	ClapTrap	*ali= new ClapTrap("ali");
	ScavTrap	mark("mark");
	FragTrap	moe("moe");

	hussein.attack("mark");
	mark.takeDamage(hussein.getAttackDamage());
	mark.beRepaired(18);
	mark.guardGate();
	mark.attack("ali");
	ali->takeDamage(mark.getAttackDamage());
	delete ali;
        moe.attack("mark");
	mark.takeDamage(moe.getAttackDamage());
	moe.highFivesGuys();
	return 0;
}