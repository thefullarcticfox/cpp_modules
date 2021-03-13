#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

class ScavTrap {
private:
	std::string		name;
	unsigned int	hp;
	unsigned int	max_hp;
	unsigned int	ep;
	unsigned int	max_ep;
	unsigned int	level;
	unsigned int	melee_dmg;
	unsigned int	ranged_dmg;
	unsigned int	armor;

	static const std::string	type;
	static const int			ccount = 5;
	static const std::string	challenges[ccount];
	ScavTrap();
public:
	ScavTrap(std::string const &name);
	virtual	~ScavTrap();
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			challengeNewcomer(void);
};

#endif
