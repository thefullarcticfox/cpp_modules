#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
	int		i = 0;

	while (i < 4)
		this->lasers[i++] = NULL;
	this->lasercount = 0;
}

MiningBarge::~MiningBarge()
{
}

MiningBarge::MiningBarge(const MiningBarge& other)
{
	*this = other;
}

MiningBarge&	MiningBarge::operator=(const MiningBarge& other)
{
	int		i = 0;

	while (i < 4)
		this->lasers[i++] = NULL;
	this->lasercount = other.lasercount;
	i = -1;
	while (++i < this->lasercount)
		this->lasers[i] = other.lasers[i];
	return (*this);
}

void			MiningBarge::equip(IMiningLaser* laser)
{
	if (this->lasercount == 4 || laser == NULL)
		return ;
	this->lasers[this->lasercount] = laser;
	this->lasercount++;
}

void			MiningBarge::mine(IAsteroid* asteroid) const
{
	int		i = 0;

	while (asteroid != NULL && i < this->lasercount)
		this->lasers[i++]->mine(asteroid);
}
