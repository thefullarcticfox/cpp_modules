#include "Fixed.class.hpp"

Fixed::Fixed() : rawvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawvalue = value * (1 << bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawvalue = int(roundf(value * (1 << bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&			Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->rawvalue = other.rawvalue;
	return (*this);
}

int				Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawvalue);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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

std::ostream&	operator<<(std::ostream& os, const Fixed& val)
{
	os << val.toFloat();
	return (os);
}
