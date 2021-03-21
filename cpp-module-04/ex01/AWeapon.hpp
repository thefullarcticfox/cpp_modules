#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon {
private:
	AWeapon();
	std::string			name;
	int					apcost;
	int					damage;
public:
	AWeapon(const std::string& name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon(const AWeapon& other);
	AWeapon&	operator=(const AWeapon& other);

	const std::string&	getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;
	virtual void		attack(void) const = 0;
};

#endif
