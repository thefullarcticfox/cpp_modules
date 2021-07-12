#include <iostream>
#include "Fixed.class.hpp"

int		main(void)
{
	Fixed		a;
	const Fixed	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << min(a, b) << std::endl;
	std::cout << max(a, b) << std::endl;
	Fixed		c(2.2f);
	Fixed		d(21);

	std::cout << a << " / 0 = " << a / Fixed(0) << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << c << " * 2 = " << c * Fixed(2) << std::endl;
	std::cout << c << " / 2 = " << c / Fixed(2) << std::endl;
	std::cout << c << " * " << c << " = " << c * c << std::endl;
	std::cout << c << " / " << c << " = " << c / c << std::endl;
	std::cout << c << " - " << c << " + " << a << " = " << c - c + a <<
		std::endl;

	std::cout << "d = " << d << std::endl;
	std::cout << d << " * 2 = " << d * Fixed(2) << std::endl;
	std::cout << d << " / 2 = " << d / Fixed(2) << std::endl;
	std::cout << c << " * " << d << " = " << c * d << std::endl;
	std::cout << d << " / " << c << " = " << d / c << std::endl;

	std::cout << "comparison ops" << std::endl;
	std::string	bools[2] = {"false", "true"};
	std::cout << c << " > " << a << " is " << bools[c > a] << std::endl;
	std::cout << c << " * -1 < " << a << " is " << bools[c * Fixed(-1) < a] <<
		std::endl;
	std::cout << c << " <= " << a << " is " << bools[c <= a] << std::endl;
	std::cout << c << " * -1 >= " << a << " is " <<
		bools[c * Fixed(-1) >= a] << std::endl;
	std::cout << c << " * 2 == " << Fixed(4.4f) << " is " <<
		bools[c * Fixed(2) == Fixed(4.4f)] << std::endl;
	std::cout << d << " / 2 != 10.5 is " <<
		bools[d / Fixed(2) != Fixed(10.5f)] << std::endl;

	return (0);
}
