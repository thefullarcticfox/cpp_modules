#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hp;
	unsigned int	max_hp;
	unsigned int	ep;
	unsigned int	max_ep;
	unsigned int	level;
	unsigned int	melee_dmg;
	unsigned int	ranged_dmg;
	unsigned int	armor;
	std::string		type;
	ClapTrap();
public:
	ClapTrap(const std::string& name);
	virtual	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap&		operator=(const ClapTrap& other);

	virtual void	rangedAttack(const std::string& target);
	virtual void	meleeAttack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
