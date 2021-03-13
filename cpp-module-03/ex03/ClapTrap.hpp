#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
protected:
	std::string			name;
	unsigned int		hp;
	unsigned int		max_hp;
	unsigned int		ep;
	unsigned int		max_ep;
	unsigned int		level;
	unsigned int		melee_dmg;
	unsigned int		ranged_dmg;
	unsigned int		armor;
	std::string			type;
	ClapTrap();
public:
	ClapTrap(std::string const &name);
	virtual	~ClapTrap();
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);

	virtual void		rangedAttack(std::string const &target);
	virtual void		meleeAttack(std::string const &target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	std::string const	&getname(void) const;
};

#endif
