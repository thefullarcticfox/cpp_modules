#include "Character.hpp"

Character::Character()
{
}

Character::Character(const std::string& name)
{
	this->name = name;
	this->ap = 40;
	this->weapon = NULL;
}

Character::~Character()
{
}

Character::Character(const Character& other)
{
	*this = other;
}

Character&			Character::operator=(const Character& other)
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

void				Character::equip(AWeapon* weapon)
{
	this->weapon = weapon;
}

void				Character::attack(Enemy* enemy)
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

const std::string&	Character::getName(void) const
{
	return (this->name);
}

int					Character::getAP(void) const
{
	return (this->ap);
}

bool				Character::isArmed(void) const
{
	return (this->weapon != NULL);
}

const std::string&	Character::getWeaponName(void) const
{
	static const std::string empty = "";

	if (this->isArmed())
		return (this->weapon->getName());
	return (empty);
}

std::ostream&		operator<<(std::ostream& os, const Character& ch)
{
	os << ch.getName() << " has " << ch.getAP() << " AP and ";
	if (ch.isArmed())
		os << "wields a " << ch.getWeaponName() << std::endl;
	else
		os << "is unarmed" << std::endl;
	return (os);
}
