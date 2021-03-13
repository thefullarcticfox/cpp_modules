#include "Human.hpp"

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "Shouting at " << target << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	std::string	names[3] = {"melee", "ranged", "shout"};
	void		(Human::*actions[3])(std::string const &) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	int			i = 0;

	while (i < 3 && (names[i].compare(action_name) != 0))
		i++;
	if (i < 3)
		(this->*actions[i])(target);
	else
		std::cout << "Error: undefined action \"" <<
			action_name << "\"" << std::endl;
}
