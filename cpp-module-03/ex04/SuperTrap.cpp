#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(), FragTrap(), NinjaTrap()
{
}

SuperTrap::SuperTrap(const std::string& name) : ClapTrap(name),
	FragTrap(name), NinjaTrap(name)
{
	this->type = "SUP3R-TP";
	this->hp =			FragTrap::init_hp;			// FragTrap::hp;
	this->max_hp =		FragTrap::init_maxhp;		// FragTrap::max_hp;
	this->ep =			NinjaTrap::init_ep;			// NinjaTrap::ep;
	this->max_ep =		NinjaTrap::init_maxep;		// NinjaTrap::max_ep;
	this->level =		1;
	this->melee_dmg =	NinjaTrap::init_mdmg;		// NinjaTrap::melee_dmg;
	this->ranged_dmg =	FragTrap::init_rdmg;		// FragTrap::ranged_dmg;
	this->armor =		FragTrap::init_armor;		// FragTrap::armor;
	std::cout << type << " " << name <<
		" says: \"Shouldn't you be murdering something about now?\"" <<
		std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << type << " " << name <<
		" says: \"The robot is dead, long live the robot!\" [dies]" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& other) : ClapTrap(other.name),
	FragTrap(other.name), NinjaTrap(other.name)
{
	*this = other;
}

SuperTrap&	SuperTrap::operator=(const SuperTrap& other)
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

void		SuperTrap::rangedAttack(const std::string& target)
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(const std::string& target)
{
	NinjaTrap::meleeAttack(target);
}
