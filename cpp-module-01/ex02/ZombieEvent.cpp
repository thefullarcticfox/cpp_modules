#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->type = "";
}

ZombieEvent::~ZombieEvent()
{
}

void		ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->type));
}

Zombie		*ZombieEvent::randomChump(void)
{
	Zombie	*z = new Zombie(this->type);
	z->announce();
	return (z);
}
