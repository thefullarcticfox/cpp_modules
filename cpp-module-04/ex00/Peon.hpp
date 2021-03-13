#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim {
private:
	Peon();
public:
	Peon(std::string const &name);
	virtual ~Peon();
	Peon(Peon const &other);
	Peon &operator=(Peon const &other);

	void	getPolymorphed(void) const;
};

#endif
