#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include <iostream>
# include <string>
# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {
public:
	StripMiner();
	virtual ~StripMiner();
	StripMiner(StripMiner const &other);
	StripMiner &operator=(StripMiner const &other);

	void	mine(IAsteroid *asteroid);
};

#endif
