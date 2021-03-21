#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>

class Human {
private:
	void	meleeAttack(const std::string& target);
	void	rangedAttack(const std::string& target);
	void	intimidatingShout(const std::string& target);
public:
	void	action(const std::string& action_name, const std::string& target);
};

#endif
