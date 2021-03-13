#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other) :
	AWeapon("Plasma Rifle", 5, 21)
{
	*this = other;
}

PlasmaRifle		&PlasmaRifle::operator=(PlasmaRifle const &other)
{
	AWeapon::operator=(other);
	return (*this);
}

void			PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
