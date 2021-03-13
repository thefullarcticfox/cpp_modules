#include "Fixed.class.hpp"

Fixed::Fixed() : rawvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->rawvalue = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawvalue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawvalue = raw;
}
