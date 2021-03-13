#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	*frag;
	ScavTrap	*scav;

	std::srand(std::time(NULL));
	frag = new FragTrap("Charles");
	frag->meleeAttack("Badass enemy");
	frag->rangedAttack("Handsome Jack");
	frag->takeDamage(5);
	frag->takeDamage(20);
	frag->takeDamage(30);
	frag->takeDamage(60);
	frag->takeDamage(177);
	frag->takeDamage(177);
	frag->beRepaired(45);
	frag->beRepaired(100);
	frag->beRepaired(54);
	frag->vaulthunter_dot_exe("Vault keeper");
	frag->vaulthunter_dot_exe("Vault keeper");
	frag->vaulthunter_dot_exe("Vault keeper");
	frag->vaulthunter_dot_exe("Vault keeper");
	frag->vaulthunter_dot_exe("Vault keeper");
	frag->vaulthunter_dot_exe("Vault keeper");
	delete (frag);
	std::cout <<
		"-------------------------------------------------" << std::endl;
	scav = new ScavTrap("Thomas");
	scav->meleeAttack("Badass enemy");
	scav->rangedAttack("Handsome Jack");
	scav->takeDamage(5);
	scav->takeDamage(20);
	scav->takeDamage(30);
	scav->takeDamage(60);
	scav->takeDamage(177);
	scav->takeDamage(177);
	scav->beRepaired(45);
	scav->beRepaired(100);
	scav->beRepaired(54);
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	delete (scav);
	return (0);
}
