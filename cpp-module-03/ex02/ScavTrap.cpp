#include "ScavTrap.hpp"

std::string const	ScavTrap::challenges[ScavTrap::ccount] = {
	"Stop me before I kill again, except don't!",
	"DO A TRIPLE BACKFLIP!",
	"Kill a badass enemy type",
	"DO A BARREL ROLL IN A VEHICLE!",
	"FACE THE SCARIEST OF YOUR FEARS! ME!"
};

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->type = "SC4V-TP";
	this->hp = 100;
	this->max_hp = 100;
	this->ep = 50;
	this->max_ep = 50;
	this->level = 1;
	this->melee_dmg = 20;
	this->ranged_dmg = 15;
	this->armor = 3;
	std::cout << type << " " << name <<
		" says: \"Look out everybody! Things are about to get awesome!\"" <<
		std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << type << " " << name <<
		" says: \"My servos... are seizing...\" [dies]" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other.name)
{
	*this = other;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
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

void		ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << type << " " << name << " scavattacks " << target <<
		" at range, causing " << ranged_dmg << " points of damage!" <<
		std::endl;
}

void		ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << type << " " << name << " scavattacks " << target <<
		" at melee, causing " << melee_dmg << " points of damage!" <<
		std::endl;
}

void		ScavTrap::challengeNewcomer(void)
{
	std::cout << type << " " << name << " challenges a newcomer to \"" <<
		challenges[std::rand() % ScavTrap::ccount] << "\"" << std::endl;

}
