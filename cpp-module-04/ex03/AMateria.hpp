#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
class AMateria;
# include "ICharacter.hpp"

class AMateria {
private:
	unsigned int		_xp;
	std::string			type;
	AMateria();
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(AMateria const &other);
	AMateria &operator=(AMateria const &other);

	std::string const	&getType(void) const;	// Returns the materia type
	unsigned int		getXP(void) const;		// Returns the Materia's XP
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter &target);
};

#endif
