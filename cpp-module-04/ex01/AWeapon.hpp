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
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon(AWeapon const &other);
	AWeapon &operator=(AWeapon const &other);

	std::string const	&getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;
	virtual void		attack(void) const = 0;
};

#endif
