#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include <iostream>
# include <string>
# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {
public:
	DeepCoreMiner();
	virtual ~DeepCoreMiner();
	DeepCoreMiner(const DeepCoreMiner& other);
	DeepCoreMiner&	operator=(const DeepCoreMiner& other);

	void			mine(IAsteroid* asteroid);
};

#endif
