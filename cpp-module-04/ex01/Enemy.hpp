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
	Enemy(int hp, const std::string& type);
	virtual ~Enemy();
	Enemy(const Enemy& other);
	Enemy&				operator=(const Enemy& other);

	const std::string&	getType(void) const;
	int					getHP(void) const;
	virtual void		takeDamage(int dmg);
};

#endif
