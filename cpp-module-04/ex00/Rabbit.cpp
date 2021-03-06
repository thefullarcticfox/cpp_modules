#include "Rabbit.hpp"

Rabbit::Rabbit() : Victim("rabbit")
{
}

Rabbit::Rabbit(const std::string& name) : Victim(name)
{
	std::cout << "* squeaks *" << std::endl;
}

Rabbit::~Rabbit()
{
	std::cout << "* painful animal noises *" << std::endl;
}

Rabbit::Rabbit(const Rabbit& other) : Victim(other.name)
{
	*this = other;
}

Rabbit&	Rabbit::operator=(const Rabbit& other)
{
	this->name = other.name;
	return (*this);
}

void	Rabbit::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a polar bear!" <<
		std::endl;
}
