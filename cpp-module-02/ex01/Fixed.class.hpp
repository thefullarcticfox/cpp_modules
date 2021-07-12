#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					rawvalue;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed&				operator=(const Fixed& other);
	int					getRawBits(void) const;
	void				setRawBits(const int raw);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream&			operator<<(std::ostream& os, const Fixed& val);

#endif
