#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
private:
	NinjaTrap();
public:
	NinjaTrap(const std::string& name);
	virtual	~NinjaTrap();
	NinjaTrap(const NinjaTrap& other);
	NinjaTrap&	operator=(const NinjaTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
	void		ninjaShoebox(const ClapTrap& trap);
	void		ninjaShoebox(const FragTrap& trap);
	void		ninjaShoebox(const ScavTrap& trap);
	void		ninjaShoebox(const NinjaTrap& trap);
};

#endif
