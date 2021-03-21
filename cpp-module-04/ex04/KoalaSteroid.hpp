#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include <string>
# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class KoalaSteroid : public IAsteroid {
private:
	std::string		name;
public:
	KoalaSteroid();
	~KoalaSteroid();
	KoalaSteroid(const KoalaSteroid& other);
	KoalaSteroid&		operator=(const KoalaSteroid& other);

	std::string			beMined(DeepCoreMiner* laser) const;
	std::string			beMined(StripMiner* laser) const;
	const std::string&	getName(void) const;
};

#endif
