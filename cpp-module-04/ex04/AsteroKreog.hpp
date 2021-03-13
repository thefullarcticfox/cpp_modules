#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include <string>
# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class AsteroKreog : public IAsteroid {
private:
	std::string		name;
public:
	AsteroKreog();
	~AsteroKreog();
	AsteroKreog(AsteroKreog const &other);
	AsteroKreog &operator=(AsteroKreog const &other);

	std::string		beMined(DeepCoreMiner *laser) const;
	std::string		beMined(StripMiner *laser) const;
	std::string		getName(void) const;
};

#endif
