#ifndef IASTEROID_HPP
# define IASTEROID_HPP

# include <string>
class DeepCoreMiner;
class StripMiner;

class IAsteroid {
public:
	virtual ~IAsteroid() {}

	virtual std::string			beMined(DeepCoreMiner*) const = 0;
	virtual std::string			beMined(StripMiner*) const = 0;
	virtual const std::string&	getName(void) const = 0;
};

#endif
