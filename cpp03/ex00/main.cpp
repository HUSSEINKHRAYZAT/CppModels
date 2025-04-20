#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap hussein("hussein");
	ClapTrap ali("ali");

	hussein.attack("ali");
	ali.takeDamage(hussein.getAttackDamage());
	ali.beRepaired(2);

	return (0);
}