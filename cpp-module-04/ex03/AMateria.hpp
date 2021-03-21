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
	AMateria(const std::string& type);
	virtual ~AMateria();
	AMateria(const AMateria& other);
	AMateria&	operator=(const AMateria& other);

	const std::string&	getType(void) const;	// Returns the materia type
	unsigned int		getXP(void) const;		// Returns the Materia's XP
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);
};

#endif
