#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	fragtrap("Charles");
	ScavTrap	scavtrap("Tommy");

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
	scavtrap.meleeAttack("Badass enemy");
	scavtrap.rangedAttack("Handsome Jack");
	scavtrap.takeDamage(5);
	scavtrap.takeDamage(20);
	scavtrap.takeDamage(30);
	scavtrap.takeDamage(60);
	scavtrap.takeDamage(177);
	scavtrap.takeDamage(177);
	scavtrap.beRepaired(45);
	scavtrap.beRepaired(100);
	scavtrap.beRepaired(54);
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	return (0);
}
