#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(AWeapon const &other)
{
	*this = other;
}

AWeapon				&AWeapon::operator=(AWeapon const &other)
{
	this->name = other.name;
	this->apcost = other.apcost;
	this->damage = other.damage;
	return (*this);
}

std::string const	&AWeapon::getName(void) const
{
	return (this->name);
}

int					AWeapon::getAPCost(void) const
{
	return (this->apcost);
}

int					AWeapon::getDamage(void) const
{
	return (this->damage);
}
