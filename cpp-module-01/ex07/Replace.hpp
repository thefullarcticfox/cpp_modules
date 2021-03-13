#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace {
private:
	static void	replacelines(std::ifstream &src, std::ofstream &dst,
						std::string const &s1, std::string const &s2);
public:
	Replace();
	~Replace();
	static void	execute(std::string const &filename,
						std::string const &s1, std::string const &s2);
};

#endif
