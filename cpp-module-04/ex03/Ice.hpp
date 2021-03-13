#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	virtual ~Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);

	AMateria*	clone(void) const;
	void		use(ICharacter &target);
};

#endif
