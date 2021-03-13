#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
class NinjaTrap;
# include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {
private:
	SuperTrap();
public:
	SuperTrap(std::string const &name);
	virtual	~SuperTrap();
	SuperTrap(SuperTrap const &other);
	SuperTrap &operator=(SuperTrap const &other);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
};

#endif
