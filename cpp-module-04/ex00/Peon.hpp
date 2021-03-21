#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim {
private:
	Peon();
public:
	Peon(const std::string& name);
	virtual ~Peon();
	Peon(const Peon& other);
	Peon&	operator=(const Peon& other);

	void	getPolymorphed(void) const;
};

#endif
