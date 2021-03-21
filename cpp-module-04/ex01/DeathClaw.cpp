#include "DeathClaw.hpp"

DeathClaw::DeathClaw() : Enemy(5000, "Death Claw")
{
	std::cout << "RRRRRRAR! * claw swinging *" << std::endl;
}

DeathClaw::~DeathClaw()
{
	std::cout << "RRRRAGHHHHHHHHHH..." << std::endl;
}

DeathClaw::DeathClaw(const DeathClaw& other) : Enemy(5000, "Death Claw")
{
	*this = other;
}

DeathClaw&		DeathClaw::operator=(const DeathClaw& other)
{
	Enemy::operator=(other);
	return (*this);
}

void			DeathClaw::takeDamage(int dmg)
{
	Enemy::takeDamage(dmg - 40);
}
