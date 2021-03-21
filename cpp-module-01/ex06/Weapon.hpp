#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
private:
	std::string 		type;
public:
	Weapon();
	Weapon(const std::string& type);
	~Weapon();
	const std::string&	getType(void) const;
	void				setType(std::string type);
};

#endif
