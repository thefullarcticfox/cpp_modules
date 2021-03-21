#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string			name;
	int					equipped;
	AMateria*			inventory[4];
	Character();
public:
	Character(const std::string& name);
	virtual ~Character();
	Character(const Character& other);
	Character&			operator=(const Character& other);

	const std::string&	getName(void) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif
