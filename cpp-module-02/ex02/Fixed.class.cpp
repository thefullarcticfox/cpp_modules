#include "Fixed.class.hpp"

Fixed::Fixed() : rawvalue(0)
{
}

Fixed::Fixed(const int value)
{
	this->rawvalue = value * (1 << bits);
}

Fixed::Fixed(const float value)
{
	this->rawvalue = int(roundf(value * float(1 << bits)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
}

Fixed			&Fixed::operator=(Fixed const &other)
{
	this->rawvalue = other.rawvalue;
	return (*this);
}

bool			Fixed::operator>(Fixed const &other) const
{
	return (this->rawvalue > other.rawvalue);
}

bool			Fixed::operator<(Fixed const &other) const
{
	return (this->rawvalue < other.rawvalue);
}

bool			Fixed::operator>=(Fixed const &other) const
{
	return (this->rawvalue >= other.rawvalue);
}

bool			Fixed::operator<=(Fixed const &other) const
{
	return (this->rawvalue <= other.rawvalue);
}

bool			Fixed::operator==(Fixed const &other) const
{
	return (this->rawvalue == other.rawvalue);
}

bool			Fixed::operator!=(Fixed const &other) const
{
	return (this->rawvalue != other.rawvalue);
}

Fixed			Fixed::operator+(Fixed const &other)
{
	Fixed	res = *this;

	res.rawvalue += other.rawvalue;
	return (res);
}

Fixed			Fixed::operator-(Fixed const &other)
{
	Fixed	res = *this;

	res.rawvalue -= other.rawvalue;
	return (res);
}

Fixed			Fixed::operator*(Fixed const &other)
{
	Fixed	res;

	res.rawvalue = int((long int)this->rawvalue * (long int)other.rawvalue
		/ (1 << bits));
	return (res);
}

Fixed			Fixed::operator/(Fixed const &other)
{
	Fixed	res;

	if (other.rawvalue == 0)
	{
		std::cout << "division by zero exception" << std::endl;
		return (res);
	}
	res.rawvalue = int((long int)this->rawvalue * (1 << bits) /
		(long int)other.rawvalue);
	return (res);
}

Fixed			Fixed::operator++(void)
{
	this->rawvalue++;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	res = *this;

	++(*this);
	return (res);
}

Fixed			Fixed::operator--(void)
{
	this->rawvalue--;
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed	res = *this;

	--(*this);
	return (res);
}

Fixed			&Fixed::min(Fixed &v1, Fixed &v2)
{
	if (v1 < v2)
		return (v1);
	return (v2);
}

Fixed const		&Fixed::min(Fixed const &v1, Fixed const &v2)
{
	if (v1 < v2)
		return (v1);
	return (v2);
}

Fixed			&Fixed::max(Fixed &v1, Fixed &v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}

Fixed const		&Fixed::max(Fixed const &v1, Fixed const &v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}

int				Fixed::getRawBits(void) const
{
	return (this->rawvalue);
}

void			Fixed::setRawBits(int const raw)
{
	this->rawvalue = raw;
}

float			Fixed::toFloat(void) const
{
	return (float(rawvalue) / float(1 << bits));
}

int				Fixed::toInt(void) const
{
	return (rawvalue / (1 << bits));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &val)
{
	os << val.toFloat();
	return (os);
}

Fixed			&min(Fixed &v1, Fixed &v2)
{
	return (Fixed::min(v1, v2));
}

Fixed const		&min(Fixed const &v1, Fixed const &v2)
{
	return (Fixed::min(v1, v2));
}

Fixed			&max(Fixed &v1, Fixed &v2)
{
	return (Fixed::max(v1, v2));
}

Fixed const		&max(Fixed const &v1, Fixed const &v2)
{
	return (Fixed::max(v1, v2));
}
