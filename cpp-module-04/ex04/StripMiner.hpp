#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include <iostream>
# include <string>
# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {
public:
	StripMiner();
	virtual ~StripMiner();
	StripMiner(const StripMiner& other);
	StripMiner&	operator=(const StripMiner& other);

	void		mine(IAsteroid* asteroid);
};

#endif
