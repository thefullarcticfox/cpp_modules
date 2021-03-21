#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class MiningBarge {
private:
	int				lasercount;
	IMiningLaser*	lasers[4];
public:
	MiningBarge();
	~MiningBarge();
	MiningBarge(const MiningBarge& other);
	MiningBarge&	operator=(const MiningBarge& other);

	void			equip(IMiningLaser* laser);
	void			mine(IAsteroid* asteroid) const;
};

#endif
