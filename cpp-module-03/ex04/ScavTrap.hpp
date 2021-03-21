#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	static const int			ccount = 5;
	static const std::string	challenges[ccount];
	ScavTrap();
public:
	ScavTrap(const std::string& name);
	virtual	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator=(const ScavTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
	void		challengeNewcomer(void);
};

#endif
