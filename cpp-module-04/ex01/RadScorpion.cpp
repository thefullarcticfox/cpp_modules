#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &other) : Enemy(80, "RadScorpion")
{
	*this = other;
}

RadScorpion		&RadScorpion::operator=(RadScorpion const &other)
{
	Enemy::operator=(other);
	return (*this);
}
