#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy {
private:
	int					hp;
	std::string			type;
	Enemy();
public:
	Enemy(int hp, std::string const &type);
	virtual ~Enemy();
	Enemy(Enemy const &other);
	Enemy &operator=(Enemy const &other);

	std::string const	&getType(void) const;
	int					getHP(void) const;
	virtual void		takeDamage(int dmg);
};

#endif
