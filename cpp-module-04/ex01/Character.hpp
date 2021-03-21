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
	AWeapon*			weapon;
	Character();
public:
	Character(const std::string& name);
	virtual ~Character();
	Character(const Character& other);
	Character&			operator=(const Character& other);

	void				recoverAP(void);
	void				equip(AWeapon* weapon);
	void				attack(Enemy* enemy);
	const std::string&	getName(void) const;
	int					getAP(void) const;
	bool				isArmed(void) const;
	const std::string&	getWeaponName(void) const;
};

std::ostream&			operator<<(std::ostream& os, const Character& ch);

#endif
