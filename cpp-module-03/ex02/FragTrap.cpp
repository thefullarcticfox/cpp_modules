#include "FragTrap.hpp"

std::string const	FragTrap::quotes[FragTrap::qcount] = {
	"Step right up, to the Bulletnator 9000!",
	"I am a tornado of death and bullets!",
	"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
	"Ha ha ha! Fall before your robot overlord!",
	"There is no way this ends badly!",
	"Eat bomb, baddie!",
	"Freeze! I don't know why I said that.",
	"It's about to get magical!"
};

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->type = "FR4G-TP";
	this->hp = 100;
	this->max_hp = 100;
	this->ep = 100;
	this->max_ep = 100;
	this->level = 1;
	this->melee_dmg = 30;
	this->ranged_dmg = 20;
	this->armor = 5;
	std::cout << type << " " << name <<
		" says: \"Resequencing combat protocols!\"" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << type << " " << name <<
		" says: \"I can see... the code...\" [dies]" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name)
{
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
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

void		FragTrap::rangedAttack(const std::string& target)
{
	std::cout << type << " " << name << " fragattacks " << target <<
		" at range, causing " << ranged_dmg << " points of damage!" <<
		std::endl;
}

void		FragTrap::meleeAttack(const std::string& target)
{
	std::cout << type << " " << name << " fragattacks " << target <<
		" at melee, causing " << melee_dmg << " points of damage!" <<
		std::endl;
}

void		FragTrap::vaulthunter_dot_exe(const std::string& target)
{
	if (ep < 25)
		std::cout << type << " " << name << " is out of energy!" << std::endl;
	else
	{
		ep -= 25;
		std::cout << type << " " << name << " screams \"" <<
			quotes[std::rand() % FragTrap::qcount] << "\"" << " and attacks " <<
			target << " for " << (std::rand() % ranged_dmg + melee_dmg) <<
			" damage" << std::endl;
	}
}
