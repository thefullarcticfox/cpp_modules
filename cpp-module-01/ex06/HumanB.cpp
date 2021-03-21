#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
