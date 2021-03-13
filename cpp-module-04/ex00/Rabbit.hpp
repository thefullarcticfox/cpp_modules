#ifndef RABBIT_HPP
# define RABBIT_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Rabbit : public Victim {
private:
	Rabbit();
public:
	Rabbit(std::string const &name);
	virtual ~Rabbit();
	Rabbit(Rabbit const &other);
	Rabbit &operator=(Rabbit const &other);

	void	getPolymorphed(void) const;
};

#endif
