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

	bool				operator>(const Fixed& other) const;
	bool				operator<(const Fixed& other) const;
	bool				operator>=(const Fixed& other) const;
	bool				operator<=(const Fixed& other) const;
	bool				operator==(const Fixed& other) const;
	bool				operator!=(const Fixed& other) const;

	Fixed				operator+(const Fixed& other) const;
	Fixed				operator-(const Fixed& other) const;
	Fixed				operator*(const Fixed& other) const;
	Fixed				operator/(const Fixed& other) const;
	Fixed&				operator++(void);						// ++i;
	Fixed				operator++(int);						// i++;
	Fixed&				operator--(void);
	Fixed				operator--(int);

	static Fixed&		min(Fixed& v1, Fixed& v2);
	static const Fixed&	min(const Fixed& v1, const Fixed& v2);
	static Fixed&		max(Fixed& v1, Fixed& v2);
	static const Fixed&	max(const Fixed& v1, const Fixed& v2);

	int					getRawBits(void) const;
	void				setRawBits(const int raw);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream&			operator<<(std::ostream& os, const Fixed& val);

Fixed&					min(Fixed& f1, Fixed& f2);
const Fixed&			min(const Fixed& v1, const Fixed& v2);
Fixed&					max(Fixed& f1, Fixed& f2);
const Fixed&			max(const Fixed& v1, const Fixed& v2);

#endif
