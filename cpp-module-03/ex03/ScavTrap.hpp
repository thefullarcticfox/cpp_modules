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
	ScavTrap(std::string const &name);
	virtual	~ScavTrap();
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);

	void						rangedAttack(std::string const &target);
	void						meleeAttack(std::string const &target);
	void						challengeNewcomer(void);
};

#endif
