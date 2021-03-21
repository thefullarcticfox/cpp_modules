#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(const std::string& name) : name(name)
{
	this->type = "CL4P-TP";
	this->hp = 0;
	this->max_hp = 0;
	this->ep = 0;
	this->max_ep = 0;
	this->level = 0;
	this->melee_dmg = 0;
	this->ranged_dmg = 0;
	this->armor = 0;
	std::cout << type << " " << name << " successfully built" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP " << name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name)
{
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	this->name = other.name;
	this->hp = other.hp;
	this->max_hp = other.max_hp;
	this->ep = other.ep;
	this->max_ep = other.max_ep;
	this->level = other.level;
	this->melee_dmg = other.melee_dmg;
	this->ranged_dmg = other.ranged_dmg;
	this->armor = other.armor;
	return (*this);
}

void		ClapTrap::rangedAttack(const std::string& target)
{
	std::cout << type << " " << name << " attacks " << target <<
		" at range, causing " << ranged_dmg << " points of damage!" <<
		std::endl;
}

void		ClapTrap::meleeAttack(const std::string& target)
{
	std::cout << type << " " << name << " attacks " << target <<
		" at melee, causing " << melee_dmg << " points of damage!" <<
		std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << type << " " << name << " already destroyed." << std::endl;
		return ;
	}
	if (amount < armor)
		amount = 0;
	else
		amount -= armor;
	if (hp < amount)
		amount = hp;
	hp -= amount;
	std::cout << type << " " << name << " takes " << amount <<
		" points of damage!" << std::endl;
	if (hp == 0)
		std::cout << type << " " << name << " has been destroyed!" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == max_hp)
	{
		std::cout << type << " " << name << " is already at max hp!" <<
			std::endl;
		return ;
	}
	if (amount >= max_hp || hp + amount > max_hp)
		amount = max_hp - hp;
	hp += amount;
	std::cout << type << " " << name << " repaired for " << amount <<
		" health points!" << std::endl;
	if (hp == max_hp)
		std::cout << type << " " << name << " is at max hp!" << std::endl;
}
