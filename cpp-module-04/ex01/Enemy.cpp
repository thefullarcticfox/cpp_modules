#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, const std::string& type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy()
{
}

Enemy::Enemy(const Enemy& other)
{
	*this = other;
}

Enemy&				Enemy::operator=(const Enemy& other)
{
	this->hp = other.hp;
	this->type = other.type;
	return (*this);
}

const std::string&	Enemy::getType(void) const
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
