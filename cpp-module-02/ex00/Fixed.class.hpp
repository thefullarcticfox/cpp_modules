#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed {
private:
	int					rawvalue;
	static const int	bits = 8;
public:
	Fixed();								// default constructor
	~Fixed();								// destructor
	Fixed(const Fixed& other);				// copy contructor
	Fixed&	operator=(const Fixed& other);	// assignation operator overload
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};

#endif
