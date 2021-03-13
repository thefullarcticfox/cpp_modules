#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
private:
	std::string			name;
	int					ap;
	AWeapon				*weapon;
	Character();
public:
	Character(std::string const &name);
	virtual ~Character();
	Character(Character const &other);
	Character &operator=(Character const &other);

	void				recoverAP(void);
	void				equip(AWeapon *weapon);
	void				attack(Enemy *enemy);
	std::string const	&getName(void) const;
	int const			&getAP(void) const;
	bool				isArmed(void) const;
	std::string const	&getWeaponName(void) const;
};

std::ostream			&operator<<(std::ostream &os, Character const &ch);

#endif
