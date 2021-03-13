#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, std::string const &type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy()
{
}

Enemy::Enemy(Enemy const &other)
{
	*this = other;
}

Enemy				&Enemy::operator=(Enemy const &other)
{
	this->hp = other.hp;
	this->type = other.type;
	return (*this);
}

std::string const	&Enemy::getType(void) const
{
	return (this->type);
}

int					Enemy::getHP(void) const
{
	return (this->hp);
}

void				Enemy::takeDamage(int dmg)
{
	if (dmg < 0)
		return ;
	if (this->hp < dmg)
		this->hp = 0;
	else
		this->hp -= dmg;
}
