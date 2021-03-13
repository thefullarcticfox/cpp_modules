#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "Unknown";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void				Weapon::setType(std::string type)
{
	this->type = type;
}
