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
	Fixed(Fixed const &other);

	Fixed				&operator=(Fixed const &other);

	bool				operator>(Fixed const &other) const;
	bool				operator<(Fixed const &other) const;
	bool				operator>=(Fixed const &other) const;
	bool				operator<=(Fixed const &other) const;
	bool				operator==(Fixed const &other) const;
	bool				operator!=(Fixed const &other) const;

	Fixed				operator+(Fixed const &other);
	Fixed				operator-(Fixed const &other);
	Fixed				operator*(Fixed const &other);
	Fixed				operator/(Fixed const &other);
	Fixed				operator++(void);						// ++i;
	Fixed				operator++(int);						// i++;
	Fixed				operator--(void);
	Fixed				operator--(int);

	static Fixed		&min(Fixed &v1, Fixed &v2);
	static Fixed const	&min(Fixed const &v1, Fixed const &v2);
	static Fixed		&max(Fixed &v1, Fixed &v2);
	static Fixed const	&max(Fixed const &v1, Fixed const &v2);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream			&operator<<(std::ostream &os, Fixed const &val);

Fixed					&min(Fixed &f1, Fixed &f2);
Fixed const				&min(Fixed const &v1, Fixed const &v2);
Fixed					&max(Fixed &f1, Fixed &f2);
Fixed const				&max(Fixed const &v1, Fixed const &v2);

#endif
