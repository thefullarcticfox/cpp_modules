#include "Pony.hpp"

Pony::Pony(std::string name)
{
	std::cout << "A wild pony was born. ";
	this->name = name;
	this->gender = Gender(std::rand() % 2);
	this->color = Color(std::rand() % 4);
	this->size = std::rand() % 40 + 100;
	this->speed = double(std::rand() % 70) / 100.0 + 0.20;
	this->x = 0.0;
	this->y = 0.0;
	this->jumps = 0;
	this->lifetime = 0;
	std::cout << "Someone named it " << this->name << "." << std::endl;
}

Pony::~Pony()
{
	std::cout << this->name << " died in pain after " <<
		this->lifetime << " moves." << std::endl;
}

std::string		Pony::strgender(Gender g)
{
	if (g == Male)
		return ("Male");
	return ("Female");
}

std::string		Pony::strcolor(Color c)
{
	if (c == White)
		return ("White");
	else if (c == Black)
		return ("Black");
	else if (c == Grey)
		return ("Grey");
	else if (c == Brown)
		return ("Brown");
	return ("None");
}

void			Pony::move(bool isjump)
{
	int		rnd;
	double	spd;

	spd = speed;
	if (isjump)
	{
		jumps++;
		spd *= 2.0;
	}
	rnd = std::rand() % 4;
	if (rnd == 0)
		x += spd;
	else if (rnd == 1)
		y += spd;
	else if (rnd == 2)
		x -= spd;
	else if (rnd == 3)
		y -= spd;
}

void			Pony::live(void)
{
	while (std::rand() % 100)
	{
		if ((std::rand() % 2) == 1)
			move(true);
		else
			move(false);
		lifetime++;
	}
}

void			Pony::printinfo(void)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::setw(11) << "Name: " << name << std::endl;
	std::cout << std::setw(11) << "Gender: " << strgender(gender) << std::endl;
	std::cout << std::setw(11) << "Color: " << strcolor(color) << std::endl;
	std::cout << std::setw(11) << "Size: " << size << std::endl;
	std::cout << std::setw(11) << "Speed: " << speed << std::endl;
	std::cout << std::setw(11) << "Jumps: " << jumps << std::endl;
	std::cout << std::setw(11) << "Lifetime: " << lifetime << std::endl;
	std::cout << std::setw(11) << "Location: " << x << ", " << y << std::endl;
}
