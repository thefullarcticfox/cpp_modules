#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	virtual ~Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);

	AMateria*	clone(void) const;
	void		use(ICharacter &target);
};

#endif
