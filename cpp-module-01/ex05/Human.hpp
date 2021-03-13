#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class Human {
private:
	const Brain	brain;
public:
	Human();
	~Human();
	const Brain	&getBrain(void) const;
	std::string identify(void);
};

#endif
