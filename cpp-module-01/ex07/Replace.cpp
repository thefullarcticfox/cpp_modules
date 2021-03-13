#include "Replace.hpp"

Replace::Replace()
{
}

Replace::~Replace()
{
}

void	Replace::replacelines(std::ifstream &src, std::ofstream &dst,
						std::string const &s1, std::string const &s2)
{
	size_t		found;
	std::string	tmp;

	while (std::getline(src, tmp))
	{
		while ((found = tmp.find(s1)) != std::string::npos)
		{
			dst << tmp.substr(0, found) << s2;
			tmp = tmp.substr(found + s1.length());
		}
		dst << tmp;
		if (!src.eof())
			dst << std::endl;
		dst.flush();
	}
}

void	Replace::execute(std::string const &filename,
						std::string const &s1, std::string const &s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: one of the strings is empty" << std::endl;
		return ;
	}
	std::ifstream	src(filename.c_str());
	if (src.is_open())
	{
		std::ofstream	dst((filename + ".replace").c_str());
		if (dst.is_open())
		{
			replacelines(src, dst, s1, s2);
			dst.close();
		}
		else
			std::cout << "Error: can't open file to write" << std::endl;
		src.close();
	}
	else
		std::cout << "Error: can't open file to read" << std::endl;
}
