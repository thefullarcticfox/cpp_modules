#ifndef RABBIT_HPP
# define RABBIT_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Rabbit : public Victim {
private:
	Rabbit();
public:
	Rabbit(const std::string& name);
	virtual ~Rabbit();
	Rabbit(const Rabbit& other);
	Rabbit&	operator=(const Rabbit& other);

	void	getPolymorphed(void) const;
};

#endif
