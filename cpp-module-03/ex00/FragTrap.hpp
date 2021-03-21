#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

class FragTrap {
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
	static const int			qcount = 8;
	static const std::string	quotes[qcount];
	FragTrap();
public:
	FragTrap(const std::string& name);
	virtual	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(const std::string& target);
};

#endif
