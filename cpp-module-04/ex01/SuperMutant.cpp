#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& other) : Enemy(170, "Super Mutant")
{
	*this = other;
}

SuperMutant&	SuperMutant::operator=(const SuperMutant& other)
{
	Enemy::operator=(other);
	return (*this);
}

void			SuperMutant::takeDamage(int dmg)
{
	Enemy::takeDamage(dmg - 3);
}
