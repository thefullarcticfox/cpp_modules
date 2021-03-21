#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace {
private:
	static
	void	replacelines(std::ifstream& src, std::ofstream& dst,
					const std::string& s1, const std::string& s2);
public:
	Replace();
	~Replace();
	static
	void	execute(const std::string& filename,
					const std::string& s1, const std::string& s2);
};

#endif
