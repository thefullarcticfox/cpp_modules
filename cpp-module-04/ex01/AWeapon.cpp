#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(const std::string& name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(const AWeapon& other)
{
	*this = other;
}

AWeapon&			AWeapon::operator=(const AWeapon& other)
{
	this->name = other.name;
	this->apcost = other.apcost;
	this->damage = other.damage;
	return (*this);
}

const std::string&	AWeapon::getName(void) const
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
