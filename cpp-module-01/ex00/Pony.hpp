#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

enum Gender {
	Male,
	Female
};

enum Color {
	White,
	Black,
	Grey,
	Brown
};

class Pony {
private:
	std::string	name;
	Gender		gender;
	Color		color;
	int			size;
	double		speed;
	double		x;
	double		y;
	int			jumps;
	int			lifetime;
	std::string	strcolor(Color c);
	std::string	strgender(Gender g);
	void		move(bool isjump);
public:
	Pony(std::string name);
	~Pony();
	void		live(void);
	void		printinfo(void);
};

#endif
