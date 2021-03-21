#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->type = "";
}

ZombieEvent::~ZombieEvent()
{
}

void		ZombieEvent::setZombieType(const std::string& type)
{
	this->type = type;
}

Zombie*		ZombieEvent::newZombie(const std::string& name)
{
	return (new Zombie(name, this->type));
}

Zombie*		ZombieEvent::randomChump(void)
{
	Zombie*	z = new Zombie(this->type);
	z->announce();
	return (z);
}
