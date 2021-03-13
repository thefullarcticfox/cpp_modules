#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain {
private:
	int			size;
public:
	Brain();
	~Brain();
	std::string identify(void) const;
};

#endif
