#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap()
{
}

NinjaTrap::NinjaTrap(std::string const &name) : ClapTrap(name)
{
	this->type = "N1NJ4-TP";
	this->hp = 60;
	this->max_hp = 60;
	this->ep = 120;
	this->max_ep = 120;
	this->level = 1;
	this->melee_dmg = 60;
	this->ranged_dmg = 5;
	this->armor = 0;
	std::cout << type << " " << name <<
		" says: \"It's time to phase you suckers out!\"" <<
		std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << type << " " << name <<
		" says: \"Metal gears... frozen solid!\" [dies]" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other) : ClapTrap(other.name)
{
	*this = other;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &other)
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

void		NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << type << " " << name << " ninjattacks " << target <<
		" at range, causing " << ranged_dmg << " points of damage!" <<
		std::endl;
}

void		NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << type << " " << name << " ninjattacks " << target <<
		" at melee, causing " << melee_dmg << " points of damage!" <<
		std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	std::cout << type << " " << name <<
		" causes segfault to the innocent CL4P-TP " << trap.getname() <<
		" (he wasn't even programmed to handle it)" << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	std::cout << type << " " << name << " slaps FR4G-TP " << trap.getname() <<
		" with some kind of fish he found in a lake (what?)" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	std::cout << type << " " << name << " stabs SC4V-TP " << trap.getname() <<
		" with a spoon from the bushes (is he mad or something)" << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	if (this == &trap)
		std::cout << type << " " << name << " hits himself with a pipe " <<
			"(who program robots like that?)" << std::endl;
	else
		std::cout << type << " " << name << " kicks butt of N1NJ4-TP " <<
			trap.getname() << " (why would you do that, " << name << ")" <<
			std::endl;
}
