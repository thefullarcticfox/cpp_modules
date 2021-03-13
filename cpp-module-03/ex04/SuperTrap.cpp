#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(), FragTrap(), NinjaTrap()
{
}

SuperTrap::SuperTrap(std::string const &name) : ClapTrap(name),
	FragTrap(name), NinjaTrap(name)
{
	this->type = "SUP3R-TP";
	this->hp = 100;								// FragTrap::hp;
	this->max_hp = 100;							// FragTrap::max_hp;
	this->ep = 120;								// NinjaTrap::ep;
	this->max_ep = 120;							// NinjaTrap::max_ep;
	this->level = 1;
	this->melee_dmg = 60;						// NinjaTrap::melee_dmg;
	this->ranged_dmg = 20;						// FragTrap::ranged_dmg;
	this->armor = 5;							// FragTrap::armor;
	std::cout << type << " " << name <<
		" says: \"Shouldn't you be murdering something about now?\"" <<
		std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << type << " " << name <<
		" says: \"The robot is dead, long live the robot!\" [dies]" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &other) : ClapTrap(other.name),
	FragTrap(other.name), NinjaTrap(other.name)
{
	*this = other;
}

SuperTrap	&SuperTrap::operator=(SuperTrap const &other)
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

void		SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
