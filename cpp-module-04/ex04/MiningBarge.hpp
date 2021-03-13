#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class MiningBarge {
private:
	int				lasercount;
	IMiningLaser	*lasers[4];
public:
	MiningBarge();
	~MiningBarge();
	MiningBarge(MiningBarge const &other);
	MiningBarge &operator=(MiningBarge const &other);

	void			equip(IMiningLaser *laser);
	void			mine(IAsteroid *asteroid) const;
};

#endif
