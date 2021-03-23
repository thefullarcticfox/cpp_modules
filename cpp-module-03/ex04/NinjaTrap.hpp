#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {
protected:
	static const int	init_hp = 60;
	static const int	init_maxhp = 60;
	static const int	init_ep = 120;
	static const int	init_maxep = 120;
	static const int	init_mdmg = 60;
	static const int	init_rdmg = 5;
	static const int	init_armor = 0;
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
