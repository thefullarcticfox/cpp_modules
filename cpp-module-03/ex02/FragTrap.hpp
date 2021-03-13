#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
	static const int			qcount = 8;
	static const std::string	quotes[qcount];
	FragTrap();
public:
	FragTrap(std::string const &name);
	virtual	~FragTrap();
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);

	void						rangedAttack(std::string const &target);
	void						meleeAttack(std::string const &target);
	void						vaulthunter_dot_exe(std::string const &target);
};

#endif
