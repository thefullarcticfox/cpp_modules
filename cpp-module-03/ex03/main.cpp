#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	FragTrap*	frag;
	ScavTrap*	scav;
	NinjaTrap*	ninja;

	std::srand(std::time(NULL));
	frag = new FragTrap("Thomas");
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
	frag->vaulthunter_dot_exe("Vault Hunter");
	frag->vaulthunter_dot_exe("Vault Hunter");
	frag->vaulthunter_dot_exe("Vault Hunter");
	frag->vaulthunter_dot_exe("Vault Hunter");
	frag->vaulthunter_dot_exe("Vault Hunter");
	frag->vaulthunter_dot_exe("Vault Hunter");
	std::cout <<
		"-------------------------------------------------" << std::endl;
	scav = new ScavTrap("James");
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
	std::cout <<
		"-------------------------------------------------" << std::endl;
	ClapTrap	clap("Charles");
	NinjaTrap	ninja2("Duke");
	ninja = new NinjaTrap("Adrian");
	ninja->meleeAttack("Badass enemy");
	ninja->rangedAttack("Handsome Jack");
	ninja->takeDamage(5);
	ninja->takeDamage(20);
	ninja->takeDamage(30);
	ninja->takeDamage(60);
	ninja->takeDamage(177);
	ninja->takeDamage(177);
	ninja->beRepaired(45);
	ninja->beRepaired(100);
	ninja->beRepaired(54);
	ninja->ninjaShoebox(clap);
	ninja->ninjaShoebox(*frag);
	ninja->ninjaShoebox(*scav);
	ninja->ninjaShoebox(*ninja);
	ninja->ninjaShoebox(ninja2);
	delete (frag);
	delete (scav);
	delete (ninja);
	return (0);
}
