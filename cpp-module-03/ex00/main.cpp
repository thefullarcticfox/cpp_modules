#include <iostream>
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	fragtrap("Charles");

	std::srand(std::time(NULL));
	fragtrap.meleeAttack("Badass enemy");
	fragtrap.rangedAttack("Handsome Jack");
	fragtrap.takeDamage(5);
	fragtrap.takeDamage(20);
	fragtrap.takeDamage(30);
	fragtrap.takeDamage(60);
	fragtrap.takeDamage(177);
	fragtrap.takeDamage(177);
	fragtrap.beRepaired(45);
	fragtrap.beRepaired(100);
	fragtrap.beRepaired(54);
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	fragtrap.vaulthunter_dot_exe("Vault keeper");
	return (0);
}
