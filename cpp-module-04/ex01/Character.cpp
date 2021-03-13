#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const &name)
{
	this->name = name;
	this->ap = 40;
	this->weapon = NULL;
}

Character::~Character()
{
}

Character::Character(Character const &other)
{
	*this = other;
}

Character			&Character::operator=(Character const &other)
{
	this->name = other.name;
	this->ap = other.ap;
	this->weapon = other.weapon;
	return (*this);
}

void				Character::recoverAP(void)
{
	ap += 10;
	if (ap > 40)
		ap = 40;
}

void				Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void				Character::attack(Enemy *enemy)
{
	if (this->weapon == NULL || enemy == NULL)
		return ;
	if (this->weapon->getAPCost() > this->ap)
	{
		std::cout << this->name << " has not enough AP to fire " <<
			this->weapon->getName() << " (has " << this->ap <<
			" < required " << this->weapon->getAPCost() << ")" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << enemy->getType() <<
		" with a " << this->weapon->getName() << std::endl;
	this->weapon->attack();
	this->ap -= this->weapon->getAPCost();
	enemy->takeDamage(this->weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete (enemy);
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

int const			&Character::getAP(void) const
{
	return (this->ap);
}

bool				Character::isArmed(void) const
{
	return (this->weapon != NULL);
}

std::string const	&Character::getWeaponName(void) const
{
	static const std::string empty = "";

	if (this->isArmed())
		return (this->weapon->getName());
	return (empty);
}

std::ostream		&operator<<(std::ostream &os, Character const &ch)
{
	os << ch.getName() << " has " << ch.getAP() << " AP and ";
	if (ch.isArmed())
		os << "wields a " << ch.getWeaponName() << std::endl;
	else
		os << "is unarmed" << std::endl;
	return (os);
}
