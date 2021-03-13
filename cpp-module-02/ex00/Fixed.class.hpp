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
	Fixed(Fixed const &other);				// copy contructor
	Fixed &operator=(Fixed const &other);	// assignation operator overload
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};

#endif
