#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string			name;
	int					equipped;
	AMateria			*inventory[4];
	Character();
public:
	Character(std::string const &name);
	virtual ~Character();
	Character(Character const &other);
	Character &operator=(Character const &other);

	std::string const	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
};

#endif
