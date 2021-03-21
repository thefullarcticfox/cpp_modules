#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = randomname(4 + (std::rand() % 11));
	this->type = "Unknown";
	this->hp = 100;
}

Zombie::Zombie(const std::string& name, const std::string& type)
{
	this->name = name;
	this->type = type;
	this->hp = 100;
	if (this->type.compare("Tank") == 0)
		this->hp = 1000;
}

Zombie::Zombie(const std::string& type)
{
	this->name = randomname(4 + (std::rand() % 11));
	this->type = type;
	this->hp = 100;
	if (this->type.compare("Tank") == 0)
		this->hp = 1000;
}

Zombie::~Zombie()
{
	std::cout << "<" << name << " (" << type << ")> has been killed." <<
		std::endl;
}

std::string	Zombie::randomname(int len)
{
	std::string	res = "";

	if (len > 0)
	{
		while (res.length() < size_t(len))
			res += char(97 + (std::rand() % 26));
	}
	return (res);
}

void		Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..." <<
		std::endl;
}

bool		Zombie::attackbase(void)
{
	this->hp -= rand() % 100;
	if (this->hp <= 0)
		return (true);
	return (false);
}

void		Zombie::settype(const std::string& type)
{
	this->type = type;
}
