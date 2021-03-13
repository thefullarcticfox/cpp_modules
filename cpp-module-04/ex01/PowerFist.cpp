#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

PowerFist::PowerFist(PowerFist const &other) : AWeapon("Power Fist", 8, 50)
{
	*this = other;
}

PowerFist		&PowerFist::operator=(PowerFist const &other)
{
	AWeapon::operator=(other);
	return (*this);
}

void			PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
