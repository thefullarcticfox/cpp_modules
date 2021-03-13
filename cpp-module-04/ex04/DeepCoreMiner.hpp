#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include <iostream>
# include <string>
# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {
public:
	DeepCoreMiner();
	virtual ~DeepCoreMiner();
	DeepCoreMiner(DeepCoreMiner const &other);
	DeepCoreMiner &operator=(DeepCoreMiner const &other);

	void	mine(IAsteroid *asteroid);
};

#endif
