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
	ScavTrap(const std::string& name);
	virtual	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator=(const ScavTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer(void);
};

#endif
